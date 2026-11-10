//claude assisted TopLevel testbench has a flow similar to RTL from SPI->R2DIF->MagnitudeDiff->LedDriver
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iostream>
#include <vector>
#include "verilatorTB.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <Vtop.h>

bool tb_called = false;

int sclkPeriod = 187;    //clk cycles in one sclk period, same as internalCount in adcSpi
int framePeriods = 16;   //sclk periods adcSpi spends on one sample
int framePulses = 15;    //sclk pulses in those periods, the arm period holds sclk low
int frameSize = 16;      //samples in one FFT frame
int main_cycles = 0;

std::vector<int> samples = {
    0x800, 0xA7C, 0xB84, 0xA7C, 0x800, 0x584, 0x47C, 0x584,
    0x800, 0xA7C, 0xB84, 0xA7C, 0x800, 0x584, 0x47C, 0x584,
    0x800, 0x9CE, 0x69E, 0x741, 0x9F4, 0x741, 0x69E, 0x9CE,
    0x800, 0x632, 0x962, 0x8BF, 0x60C, 0x8BF, 0x962, 0x632
};

std::vector<int> dataIn, resetN;  //one entry per sclk period, not per clk

void buildStim(){
    dataIn.push_back(0);   //one period of reset lines the sclk counter up with the frames below
    resetN.push_back(0);
    for(int sample : samples){
        for(int p = 0; p < 4; p++){     //period 0 arms the SPI, 1 and 2 are the MCP3201 sample clocks, 3 is the null bit
            dataIn.push_back(0);
            resetN.push_back(1);
        }
        for(int b = 11; b >= 0; b--){   //periods 4 to 15 carry the 12 data bits, MSB first
            dataIn.push_back((sample >> b) & 1);
            resetN.push_back(1);
        }
    }
    for(int p = 0; p < 4*framePeriods; p++){  //idle tail, four more conversions of zeros, long enough for the display
        dataIn.push_back(0);                  //to refresh and be checked but short of the 16 a third FFT frame needs
        resetN.push_back(1);
    }
    main_cycles = dataIn.size() * sclkPeriod;
}

int spiToVal(std::vector<int> pulses){  //one SPI frame, one bit per sclk pulse
    int val = 0;                        //pulses 0 and 1 are the sample clocks, 2 the null bit, 3 to 14 the data
    for(size_t p = 3; p < pulses.size(); p++){
        val = (val << 1) | pulses[p];
    }
    return val;
}

std::vector<int16_t> wRe, wIm;

void loadTwiddles(){
    std::ifstream reHex("twiddleRE.hex"), imHex("twiddleIM.hex");
    uint32_t re, im;
    while(reHex >> std::hex >> re && imHex >> std::hex >> im){
        wRe.push_back((int16_t)re);
        wIm.push_back((int16_t)im);
    }
}

void ValToOutput(std::vector<int> vals, std::vector<int16_t> &re, std::vector<int16_t> &im){
    int n = vals.size();
    re.resize(n);
    im.resize(n);
    for(int s = 0; s < n; s++){
        re[s] = (int16_t)((vals[s] ^ 0x800) << 4);   //top.sv pads the 12 bit sample with 4 zero LSBs
        im[s] = 0;
    }
    for(int i = n; i >= 2; i /= 2){
        int half = i / 2;
        for(int k = 0; k < n; k += i){
            for(int j = 0; j < half; j++){
                int index = j * (n / i);
                int16_t addRE = (int16_t)((re[k+j] + re[k+j+half]) >> 1);
                int16_t addIM = (int16_t)((im[k+j] + im[k+j+half]) >> 1);
                int16_t subRE = (int16_t)((re[k+j] - re[k+j+half]) >> 1);
                int16_t subIM = (int16_t)((im[k+j] - im[k+j+half]) >> 1);
                int16_t multRE, multIM;
                if(i <= 4 && index == 0){   //last two stages have no multiplier, SDFCell0 and Cell1BFU
                    multRE = subRE;
                    multIM = subIM;
                } else if(i == 4){          //index 4 is -j, Cell1BFU swaps and negates instead of multiplying
                    multRE = subIM;
                    multIM = (int16_t)-subRE;
                } else {
                    multRE = (int16_t)((subRE*wRe[index] - subIM*wIm[index]) >> 15);
                    multIM = (int16_t)((subRE*wIm[index] + subIM*wRe[index]) >> 15);
                }
                re[k+j] = addRE;
                im[k+j] = addIM;
                re[k+j+half] = multRE;
                im[k+j+half] = multIM;
            }
        }
    }
}

uint8_t OutputToBin(int16_t re, int16_t im){
    uint16_t a = (re < 0) ? (uint16_t)-re : (uint16_t)re;
    uint16_t b = (im < 0) ? (uint16_t)-im : (uint16_t)im;
    uint16_t mx = (a > b) ? a : b;
    uint16_t mn = (a > b) ? b : a;
    uint16_t mag = (uint16_t)(mx + (mn >> 1));
    return (mag & 0x8000) ? 0xFF : (uint8_t)(mag >> 7);
}

int magToLevel(uint8_t mag){
    int level = 0;
    while(mag >> level) level++;
    return level;
}

std::vector<int> bitRevIndex = {8, 4, 12, 2, 10, 6, 14, 1}; //ledDriver writes bit reversed, so columns 1 to 8 read bins 1 to 8

int decayFrames = 2;
std::vector<int> held(8, 0);
int framesShown = 0;

std::vector<uint8_t> frameRows(std::vector<int> vals){
    std::vector<int16_t> re, im;
    ValToOutput(vals, re, im);
    bool decay = framesShown % decayFrames == decayFrames - 1;
    framesShown++;
    std::vector<uint8_t> rows;
    for(size_t c = 0; c < bitRevIndex.size(); c++){
        int slot = bitRevIndex[c];
        int level = magToLevel(OutputToBin(re[slot], im[slot]));
        int decayed = held[c] - (decay && held[c] > 0);
        held[c] = std::max(level, decayed);
        rows.push_back((uint8_t)(0xFF >> (8 - held[c])));
    }
    return rows;
}

void printRows(const char *name, std::vector<uint8_t> rows){
    std::cout << name;
    for(uint8_t row : rows){
        std::cout << " " << std::bitset<8>(row);
    }
    std::cout << std::endl;
}

class TopTxIn{
    public:
        bool adcData, resetN, startTrans;
        int tick;
};

class TopTxOut{
    public:
        int colOut;   //one hot, column 1 is 0x01 up to column 8 at 0x80
        uint8_t rowOut;
        int tick;
};

std::deque<TopTxIn*> genTx(){
    std::deque<TopTxIn*> ins;
    for(size_t p = 0; p < dataIn.size(); p++){
        for(int c = 0; c < sclkPeriod; c++){
            TopTxIn *tx = new TopTxIn();
            tx->adcData = dataIn[p];
            tx->resetN = resetN[p];
            tx->startTrans = 1;
            ins.push_back(tx);
        }
    }
    return ins;
}


//scoreboard

int readDivCount = 64;                 //ledDriver parameter, set by -GreadDivCount in the Makefile
int refreshCycles = 8*readDivCount;    //clk cycles the ledDriver takes to walk its 8 display positions

class TopScb{
    private:
        std::vector<int> pulses, vals;  //bits of the SPI frame coming in, then whole samples
        std::vector<uint8_t> rows;      //the 8 rows this frame must put on the display, empty when none is due
        int column = 0;                 //how many columns of this frame have been checked
        int checkAt = 0;                //tick from which the display is certain to hold this frame

        void checkColumn(TopTxOut *tx){
            int solCol = 1 << column;
            uint8_t solRow = rows[column];
            if(tx->colOut == solCol && tx->rowOut == solRow){
                std::cout << "Frame " << frames_fed << " column " << column + 1 << " success  rowOut "
                          << std::bitset<8>(tx->rowOut) << std::endl;
            } else {
                std::cout << "Frame " << frames_fed << " column " << column + 1 << " failed at tick " << tx->tick << std::endl;
                std::cout << "  DUT colOut " << std::bitset<8>(tx->colOut) << "  rowOut " << std::bitset<8>(tx->rowOut) << std::endl;
                std::cout << "  TB  colOut " << std::bitset<8>(solCol)     << "  rowOut " << std::bitset<8>(solRow) << std::endl;
                error_count++;
            }
            column++;
            if(column == (int)rows.size()){   //whole display checked, nothing due until the next frame
                frames_checked++;
                rows.clear();
                column = 0;
            }
        }
    public:
        int frames_fed = 0;
        int frames_checked = 0;

        void writeIn(TopTxIn *tx){
            pulses.push_back(tx->adcData);
            if((int)pulses.size() == framePulses){
                vals.push_back(spiToVal(pulses));
                pulses.clear();
            }
            if((int)vals.size() == frameSize){
                rows = frameRows(vals);
                vals.clear();
                frames_fed++;
                checkAt = tx->tick + refreshCycles;   //the FFT and one whole refresh both finish inside this
                std::cout << "Frame " << frames_fed << " fed, display must hold these rows from tick " << checkAt << std::endl;
                printRows("  TB rows: ", rows);
            }
            delete tx;
        }

        void writeOut(TopTxOut *tx){
            bool nothingDue = rows.empty() || tx->tick < checkAt;   //no frame to check, or the display has not caught up
            bool midRefresh = column == 0 && tx->colOut != 1;       //never start checking halfway through a refresh
            if(!nothingDue && !midRefresh) checkColumn(tx);
            delete tx;
        }

        void report(){
            if(!tb_called) std::cout << "colOut never driven *ERROR*" << std::endl;
            if(frames_checked != frames_fed){
                std::cout << "checked " << frames_checked << " of " << frames_fed << " FFT frames *ERROR*" << std::endl;
                error_count++;
            }
        }
};

//drivers

class TopDrive{
    private:
        Vtop *dut;
    public:
        TopDrive(Vtop *dut){
            this->dut = dut;
        }
        void drive(TopTxIn *tx){
            dut->adcData = tx->adcData;
            dut->resetN = tx->resetN;
            dut->startTrans = tx->startTrans;
            delete tx;
        }
};

//monitors

class TopmonIn{
    private:
        Vtop *dut;
        TopScb *scb;
        int tick_count = 0;
        bool prevSclk = 0;
    public:
        TopmonIn(Vtop *dut, TopScb *scb){
            this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            tick_count++;
            if(dut->adcSclk && !prevSclk){  //adcSpi shifts dataIn on the sclk rising edge, one bit per period
                TopTxIn *tx = new TopTxIn();
                tx->adcData = dut->adcData;
                tx->resetN = dut->resetN;
                tx->startTrans = dut->startTrans;
                tx->tick = tick_count;
                scb->writeIn(tx);
            }
            prevSclk = dut->adcSclk;
        }
};

class TopmonOut{
    private:
        Vtop *dut;
        TopScb *scb;
        int tick_count = 0;
        uint8_t prevCol = 0;
    public:
        TopmonOut(Vtop *dut, TopScb *scb){
            this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            tick_count++;
            if(dut->colOut != 0 && dut->colOut != prevCol){
                TopTxOut *tx = new TopTxOut();
                tb_called = true;
                tx->colOut = dut->colOut;
                tx->rowOut = dut->rowOut;
                tx->tick = tick_count;
                scb->writeOut(tx);
            }
            prevCol = dut->colOut;
        }
};

int main(int argc, char** argv){
    Vtop *tb = new Vtop;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_top.vcd");
    if((int)samples.size() % frameSize != 0)
        std::cout << "samples don't fill whole FFT frames *ERROR*" << std::endl;
    TopTxIn *tx;
    loadTwiddles();
    buildStim();
    std::deque<TopTxIn*> in = genTx();
    TopDrive *drv = new TopDrive(tb);
    TopScb *scb = new TopScb();

    TopmonIn *monIn = new TopmonIn(tb, scb);
    TopmonOut *monOut = new TopmonOut(tb, scb);

    for(int i = 0; i < main_cycles; i++){
        if(in.empty()){ std::cout << "Error inputs Empty" << std::endl; exit(1);}
        tx = in.front();
        in.pop_front();
        drv->drive(tx);
        tick(tb,tfp);
        monIn->monitor();
        monOut->monitor();
    }
    scb->report();
    delete monIn;
    delete monOut;
    delete scb;
    delete drv;
    return finish(tb,tfp);
};

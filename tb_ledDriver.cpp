#include <bitset>
#include <deque>
#include <iostream>
#include <vector>
#include "verilatorTB.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VledDriver.h>

bool tb_called = false;

std::vector<uint8_t> magStim = {
    0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02,
    0x01, 0xFF, 0x7E, 0x3C, 0x11, 0x09, 0x05, 0x33
};

std::vector<int> reset, valid;
uint16_t main_cycles = 0;
int frameCycles = 128;
int checkStart = 2 + frameCycles;

void formatCtrl(){
    for(int i = 0; i < 2; i++){
        reset.push_back(0);
        valid.push_back(0);
    }
    for(size_t i = 0; i < magStim.size(); i++){
        reset.push_back(1);
        valid.push_back(1);
    }
    while((int)reset.size() < checkStart + frameCycles + 4){
        reset.push_back(1);
        valid.push_back(0);
    }
    main_cycles = reset.size();
};

class LDTxIn{
    public:
        uint8_t magIn;
        bool validI, reset;
        int tick;
};

class LDTxOut{
    public:
        uint8_t colOut, rowOut;
        int tick;
};

uint8_t model(uint8_t mag){
    if(mag & 0x80) return 0xFF;
    if(mag & 0x40) return 0x7F;
    if(mag & 0x20) return 0x3F;
    if(mag & 0x10) return 0x1F;
    if(mag & 0x08) return 0x0F;
    if(mag & 0x04) return 0x07;
    if(mag & 0x02) return 0x03;
    return 0x01;
}

std::deque<LDTxIn*> TxLDGen(){
    std::deque<LDTxIn*> seq;
    int dataIndx = 0;
    for(int i = 0; i < main_cycles; i++){
        LDTxIn *tx = new LDTxIn();
        if(valid[i]){
            tx->magIn = magStim[dataIndx];
            dataIndx++;
        } else {
            tx->magIn = 0x00;
        }
        tx->validI = valid[i];
        tx->reset = reset[i];
        tx->tick = i;
        seq.push_back(tx);
    }
    return seq;
};

class LDDrive{
    private:
        VledDriver *dut;
    public:
        LDDrive(VledDriver *dut){
            this->dut = dut;
        }
        void drive(LDTxIn *tx){
            dut->magIn = tx->magIn;
            dut->validI = tx->validI;
            dut->reset = tx->reset;
            delete tx;
        }
};


std::string bin(uint8_t v){
    return std::bitset<8>(v).to_string();
}

std::vector<int> bitRevIndex = {8, 4, 12, 2, 10, 6, 14, 1}; //just index 1 to 8 of a 4 bit number

class LDScb{
    private:
        std::vector<uint8_t> mags;
    public:
        int check_index = 0;

        void writeIn(LDTxIn *tx){
            if(tx->validI && tx->reset) mags.push_back(tx->magIn);
            delete tx;
        }

        void writeOut(LDTxOut *tx){
            if(check_index >= (int)bitRevIndex.size()){
                delete tx;
                return;
            }
            if(mags.size() != magStim.size()){
                std::cout << "captured " << mags.size() << " of " << magStim.size() << " writes *ERROR*" << std::endl;
                error_count++;
                delete tx;
                return;
            }
            uint8_t expMag = mags[bitRevIndex[check_index]];
            uint8_t expCol = (uint8_t)(1 << check_index);
            uint8_t expRow = model(expMag);

            if(tx->colOut != expCol || tx->rowOut != expRow){
                std::cout << "Column " << check_index << " failed at tick " << tx->tick << std::endl;
                std::cout << "magIn: " << bin(expMag) << std::endl;
                std::cout << "colOut DUT: " << bin(tx->colOut) << "  colOut TB: " << bin(expCol) << std::endl;
                std::cout << "rowOut DUT: " << bin(tx->rowOut) << "  rowOut TB: " << bin(expRow) << std::endl;
                error_count++;
            } else {
                std::cout << "Column " << check_index << " success" << std::endl;
                std::cout << "magIn: " << bin(expMag) << "  colOut: " << bin(tx->colOut) << "  rowOut: " << bin(tx->rowOut) << std::endl;
            }
            check_index++;
            delete tx;
        }
};

class LDmonIn{
    private:
        VledDriver *dut;
        LDScb *scb;
        int tick_count = 0;
    public:
        LDmonIn(VledDriver *dut, LDScb *scb){
            this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            LDTxIn *tx = new LDTxIn();
            tx->magIn = dut->magIn;
            tx->validI = dut->validI;
            tx->reset = dut->reset;
            tx->tick = tick_count++;
            scb->writeIn(tx);
        }
};

class LDmonOut{
    private:
        VledDriver *dut;
        LDScb *scb;
        int tick_count = 0;
        uint8_t prevCol = 0;
    public:
        LDmonOut(VledDriver *dut, LDScb *scb){
            this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            int t = tick_count++;
            if(dut->colOut != 0 && dut->colOut != prevCol && t >= checkStart){
                LDTxOut *tx = new LDTxOut();
                tb_called = true;
                tx->colOut = dut->colOut;
                tx->rowOut = dut->rowOut;
                tx->tick = t;
                scb->writeOut(tx);
            }
            prevCol = dut->colOut;
        }
};

int main(int argc, char** argv){
    VledDriver *tb = new VledDriver;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_LEDDr.vcd");
    formatCtrl();
    LDTxIn *tx;
    std::deque<LDTxIn*> in = TxLDGen();
    LDDrive *drv = new LDDrive(tb);
    LDScb *scb = new LDScb();

    LDmonIn *monIn = new LDmonIn(tb, scb);
    LDmonOut *monOut = new LDmonOut(tb, scb);

    for(int i = 0; i < main_cycles; i++){
        if(in.empty()){ std::cout << "Error inputs Empty" << std::endl; exit(1);}
        tx = in.front();
        in.pop_front();
        drv->drive(tx);
        tick(tb,tfp);
        monIn->monitor();
        monOut->monitor();
    }
    if(!tb_called) std::cout << "colOut never asserted *ERROR*" << std::endl;
    if(scb->check_index != (int)bitRevIndex.size()){
        std::cout << "checked " << scb->check_index << " of " << bitRevIndex.size() << " columns *ERROR*" << std::endl;
        error_count++;
    }
    delete monIn;
    delete monOut;
    delete scb;
    delete drv;
    return finish(tb,tfp);
};

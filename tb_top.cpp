#include <deque>
#include <iostream>
#include <vector>
#include "verilatorTB.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <Vtop.h>

bool tb_called = false;

int sclkPeriod = 279;
int readDivCount = 64;
int frameCycles = 16*readDivCount;

std::vector<int> samples = {2282, 3459, 2892, 3042, 2601,  631,  422, 1658,
                            1814, 2617, 4004, 3034, 1495, 1485,  874,  458};

std::vector<int> sol = {0x01, 0x1F, 0x01, 0x01, 0x0F, 0x01, 0x01, 0x01};

class TopTxIn{
    public:
        bool startTrans, adcData, resetN;
};

class TopTxOut{
    public:
        int colOut, rowOut;
};

int leadTicks = 6*sclkPeriod;
int sampleTicks = 17*sclkPeriod;

std::deque<TopTxIn*> genTx(){
    std::deque<TopTxIn*> ins;
    for(int t = 0; t < leadTicks + sampleTicks*(int)samples.size(); t++){
        int sample = (t - leadTicks)/sampleTicks;
        int period = ((t - leadTicks)/sclkPeriod)%17;
        TopTxIn *tx = new TopTxIn();
        tx->startTrans = 1;
        tx->resetN = (t >= sclkPeriod);
        tx->adcData = (t >= leadTicks && period < 12) ? (samples[sample] >> (11 - period)) & 1 : 0;
        ins.push_back(tx);
    }
    return ins;
};

class TopDrive{
    private:
        Vtop *dut;
    public:
        TopDrive(Vtop *dut){
            this->dut = dut;
        }
        void drive(TopTxIn *tx){
            dut->startTrans = tx->startTrans;
            dut->adcData = tx->adcData;
            dut->resetN = tx->resetN;
            delete tx;
        }
};

class TopScb{
    public:
        int out_count = 0;

        void writeOut(TopTxOut *tx){
            if(tx->colOut != (1 << out_count) || tx->rowOut != sol[out_count]){
                std::cout << "FAILED column " << out_count + 1 << std::endl;
                std::cout << "DUT colOut:   " << std::hex << tx->colOut << "  rowOut: " << tx->rowOut << std::dec << std::endl;
                std::cout << "Testbench Sol:   " << std::hex << (1 << out_count) << "  rowOut: " << sol[out_count] << std::dec << std::endl;
                error_count++;
            }else{
                std::cout << "SUCCESS column " << out_count + 1 << std::endl;
                std::cout << "rowOut:  " << std::hex << tx->rowOut << std::dec << std::endl;
            }
            out_count++;
            delete tx;
        }
};

class TopMonOut{
    private:
        Vtop *dut;
        TopScb *scb;
        int prevCol = 0;
    public:
        TopMonOut(Vtop *dut, TopScb *scb){
            this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            if(dut->colOut != prevCol && dut->colOut != 0 && scb->out_count < (int)sol.size()){
                if(scb->out_count > 0 || dut->colOut == 1){
                    TopTxOut *tx = new TopTxOut();
                    tb_called = true;
                    tx->colOut = dut->colOut;
                    tx->rowOut = dut->rowOut;
                    scb->writeOut(tx);
                }
            }
            prevCol = dut->colOut;
        }
};

int main(int argc, char** argv){
    Vtop *tb = new Vtop;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_top.vcd");
    TopTxIn *tx;
    std::deque<TopTxIn*> in = genTx();
    int total_ticks = in.size();
    TopDrive *drv = new TopDrive(tb);
    TopScb *scb = new TopScb();
    TopMonOut *monOut = new TopMonOut(tb, scb);

    for(int i = 0; i < total_ticks; i++){
        if(in.empty()){ std::cout << "Error inputs Empty" << std::endl; exit(1);}
        tx = in.front();
        in.pop_front();
        drv->drive(tx);
        tick(tb,tfp);
    }

    tb->startTrans = 0;
    for(int i = 0; i < 3*frameCycles; i++){
        tick(tb,tfp);
        monOut->monitor();
    }

    if(!tb_called) std::cout << "colOut never asserted *ERROR*" << std::endl;
    if(scb->out_count != (int)sol.size()){
        std::cout << "checked " << scb->out_count << " of " << sol.size() << " columns *ERROR*" << std::endl;
        error_count++;
    }
    delete monOut;
    delete scb;
    delete drv;
    return finish(tb,tfp);
}

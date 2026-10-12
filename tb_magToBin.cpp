#include <deque>
#include <iostream>
#include <fstream>
#include <vector>
#include "verilatorTB.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VmagToBin.h>

bool tb_called = false;

const int latency = 2;
const int resetCycles = 2;
const int gapAt = 6;
const int gapCycles = 3;
const int tailCycles = 4;

std::vector<int> reset, valid;
uint16_t main_cycles = 0;

std::ifstream inRealHex("fftOutRE.hex");
std::ifstream inImagHex("fftOutIM.hex");
std::vector<uint16_t> inRe, inIm;
uint32_t reI, imI;

void formatIns(){
    while(inRealHex >> std::hex >> reI && inImagHex >> std::hex >> imI){
        inRe.push_back((uint16_t)reI);
        inIm.push_back((uint16_t)imI);
    }
};

void formatCtrl(){
    int samples = inRe.size();
    for(int i = 0; i < resetCycles; i++){
        reset.push_back(0);
        valid.push_back(0);
    }
    for(int i = 0; i < samples; i++){
        if(i == gapAt){
            for(int j = 0; j < gapCycles; j++){
                reset.push_back(1);
                valid.push_back(0);
            }
        }
        reset.push_back(1);
        valid.push_back(1);
    }
    for(int i = 0; i < tailCycles; i++){
        reset.push_back(1);
        valid.push_back(0);
    }
    main_cycles = reset.size();
};

class MTBTxIn{
    public:
        uint16_t FFTOutRE, FFTOutIM;
        bool validI, reset;
        int tick;
};

class MTBTxOut{
    public:
        uint8_t MagOut;
        bool validO;
        int tick;
};

uint8_t model(MTBTxIn *in){
    uint16_t re = (in->FFTOutRE & 0x8000) ? (uint16_t)(~in->FFTOutRE + 1) : in->FFTOutRE;
    uint16_t im = (in->FFTOutIM & 0x8000) ? (uint16_t)(~in->FFTOutIM + 1) : in->FFTOutIM;
    uint16_t mx = (re > im) ? re : im;
    uint16_t mn = (re > im) ? im : re;
    uint16_t mag = (uint16_t)(mx + (mn >> 1));
    return (uint8_t)(mag >> 8);
}

std::deque<MTBTxIn*> TxMTBGen(){
    std::deque<MTBTxIn*> seq;
    int dataIndx = 0;
    for(int i = 0; i < main_cycles; i++){
        MTBTxIn *tx = new MTBTxIn();
        if(valid[i]){
            tx->FFTOutRE = inRe[dataIndx];
            tx->FFTOutIM = inIm[dataIndx];
            dataIndx++;
        } else {
            tx->FFTOutRE = 0x7FFF;
            tx->FFTOutIM = 0x7FFF;
        }
        tx->validI = valid[i];
        tx->reset = reset[i];
        tx->tick = i;
        seq.push_back(tx);
    }
    return seq;
};

class MTBDrive{
    private:
        VmagToBin *dut;
    public:
        MTBDrive(VmagToBin *dut){
            this->dut = dut;
        }
        void drive(MTBTxIn *tx){
            dut->FFTOutRE = tx->FFTOutRE;
            dut->FFTOutIM = tx->FFTOutIM;
            dut->validI = tx->validI;
            dut->reset = tx->reset;
            delete tx;
        }
};

class MTBScb{
    private:
        std::deque<MTBTxIn*> in_q;
    public:
        int out_count = 0;
        int expected_outs = 0;

        void writeIn(MTBTxIn *tx){
            if(tx->validI && tx->reset) expected_outs++;
            in_q.push_back(tx);
        }

        void writeOut(MTBTxOut *tx){
            while(!in_q.empty() && in_q.front()->tick < tx->tick - latency){
                delete in_q.front();
                in_q.pop_front();
            }
            if(in_q.empty() || in_q.front()->tick != tx->tick - latency){
                std::cout << "No matching input for output at tick " << tx->tick << " *ERROR*" << std::endl;
                error_count++;
                delete tx;
                return;
            }
            MTBTxIn *in = in_q.front();
            in_q.pop_front();

            uint8_t sol = model(in);

            if(tx->MagOut != sol){
                std::cout << "Mag failed" << std::endl;
                std::cout << "Inputs:   RE " << std::hex << in->FFTOutRE << "  IM " << in->FFTOutIM << std::dec << std::endl;
                std::cout << "Mag Value DUT: " << std::hex << (int)tx->MagOut << "  Mag Value TB: " << (int)sol << std::dec << std::endl;
                error_count++;
            } else {
                std::cout << "Mag success" << std::endl;
                std::cout << "Mag Value: " << std::hex << (int)tx->MagOut << std::dec << std::endl;
            }
            out_count++;
            delete in;
            delete tx;
        }
};

class MTBmonIn{
    private:
        VmagToBin *dut;
        MTBScb *scb;
        int tick_count = 0;
    public:
        MTBmonIn(VmagToBin *dut, MTBScb *scb){
            this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            MTBTxIn *tx = new MTBTxIn();
            tx->FFTOutRE = dut->FFTOutRE;
            tx->FFTOutIM = dut->FFTOutIM;
            tx->validI = dut->validI;
            tx->reset = dut->reset;
            tx->tick = tick_count++;
            scb->writeIn(tx);
        }
};

class MTBmonOut{
    private:
        VmagToBin *dut;
        MTBScb *scb;
        int tick_count = 0;
    public:
        MTBmonOut(VmagToBin *dut, MTBScb *scb){
            this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            int t = tick_count++;
            if(dut->validO == 1){
                MTBTxOut *tx = new MTBTxOut();
                tb_called = true;
                tx->MagOut = dut->MagOut;
                tx->validO = dut->validO;
                tx->tick = t;
                scb->writeOut(tx);
            }
        }
};

int main(int argc, char** argv){
    VmagToBin *tb = new VmagToBin;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_magToBin.vcd");
    formatIns();
    if(inRe.empty()){
        std::cout << "no stimulus, run python3 magGen.py *ERROR*" << std::endl;
        error_count++;
        return finish(tb,tfp);
    }
    formatCtrl();
    MTBTxIn *tx;
    std::deque<MTBTxIn*> in = TxMTBGen();
    MTBDrive *drv = new MTBDrive(tb);
    MTBScb *scb = new MTBScb();

    MTBmonIn *monIn = new MTBmonIn(tb, scb);
    MTBmonOut *monOut = new MTBmonOut(tb, scb);

    for(int i = 0; i < main_cycles; i++){
        if(in.empty()){ std::cout << "Error inputs Empty" << std::endl; exit(1);}
        tx = in.front();
        in.pop_front();
        drv->drive(tx);
        tick(tb,tfp);
        monIn->monitor();
        monOut->monitor();
    }
    if(!tb_called) std::cout << "validO never asserted *ERROR*" << std::endl;
    if(scb->out_count != scb->expected_outs){
        std::cout << "validO count " << scb->out_count << " expected " << scb->expected_outs << " *ERROR*" << std::endl;
        error_count++;
    }
    if(scb->out_count != (int)inRe.size()){
        std::cout << "checked " << scb->out_count << " of " << inRe.size() << " streamed samples *ERROR*" << std::endl;
        error_count++;
    }
    delete monIn;
    delete monOut;
    delete scb;
    delete drv;
    return finish(tb,tfp);
};

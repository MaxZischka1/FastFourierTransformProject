#include <deque>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include "verilatorTB.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VSBM16.h>

bool tb_called = false;

class SBMTxIn{
    public:
        int16_t re, im;
        bool valid, reset;
};

class SBMTxOut{
    public:
        int16_t re, im;
};

std::deque<SBMTxIn*> genTx(){
    std::mt19937 rng(1);
    std::deque<SBMTxIn*> ins;
    for(int i = 0; i < 20000; i++){
        SBMTxIn *tx = new SBMTxIn();
        tx->reset = i >= 4;
        tx->valid = tx->reset && rng() % 4 != 0;
        tx->re = (int16_t)rng();
        tx->im = (int16_t)rng();
        ins.push_back(tx);
    }
    return ins;
}

class SBMDrive{
    private:
        VSBM16 *dut;
    public:
        SBMDrive(VSBM16 *dut){
            this->dut = dut;
        }
        void drive(SBMTxIn *tx){
            dut->reset = tx->reset;
            dut->valid = tx->valid;
            dut->en = 1;
            dut->interOddRE1 = tx->re;
            dut->interOddIM1 = tx->im;
        }
};

class SBMScb{
    private:
        std::vector<int16_t> wRe, wIm;
        std::deque<SBMTxOut*> sol;
        int counter = 0;
    public:
        int checks = 0;

        SBMScb(){
            std::ifstream reHex("twiddleRE.hex"), imHex("twiddleIM.hex");
            uint32_t re, im;
            while(reHex >> std::hex >> re && imHex >> std::hex >> im){
                wRe.push_back((int16_t)re);
                wIm.push_back((int16_t)im);
            }
        }

        void writeIn(SBMTxIn *tx){
            if(tx->valid){
                SBMTxOut *exp = new SBMTxOut();
                uint32_t re = (uint32_t)((int64_t)tx->re * wRe[counter] - (int64_t)tx->im * wIm[counter]);
                uint32_t im = (uint32_t)((int64_t)tx->re * wIm[counter] + (int64_t)tx->im * wRe[counter]);
                exp->re = (int16_t)(re >> 15);
                exp->im = (int16_t)(im >> 15);
                sol.push_back(exp);
                counter = (counter + 1) % wRe.size();
            }
            delete tx;
        }

        void writeOut(SBMTxOut *tx){
            if(sol.empty()){
                std::cout << "validO with no input *ERROR*" << std::endl;
                error_count++;
                delete tx;
                return;
            }
            SBMTxOut *exp = sol.front();
            sol.pop_front();
            if(tx->re != exp->re || tx->im != exp->im){
                if(error_count < 8){
                    std::cout << "Mismatch at check " << checks << std::endl;
                    std::cout << "  DUT re " << tx->re << "  im " << tx->im << std::endl;
                    std::cout << "  TB  re " << exp->re << "  im " << exp->im << std::endl;
                }
                error_count++;
            }
            checks++;
            delete exp;
            delete tx;
        }

        void report(){
            std::cout << checks << " checks, " << sol.size() << " still pending" << std::endl;
            if(sol.size() > 2) error_count++;
        }
};

class SBMmonOut{
    private:
        VSBM16 *dut;
        SBMScb *scb;
    public:
        SBMmonOut(VSBM16 *dut, SBMScb *scb){
            this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            if(dut->validO){
                tb_called = true;
                SBMTxOut *tx = new SBMTxOut();
                tx->re = (int16_t)dut->dOutOddRE;
                tx->im = (int16_t)dut->dOutOddIM;
                scb->writeOut(tx);
            }
        }
};

int main(int argc, char** argv){
    VSBM16 *tb = new VSBM16;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_SBM16.vcd");
    std::deque<SBMTxIn*> in = genTx();
    SBMDrive *drv = new SBMDrive(tb);
    SBMScb *scb = new SBMScb();
    SBMmonOut *monOut = new SBMmonOut(tb, scb);

    while(!in.empty()){
        SBMTxIn *tx = in.front();
        in.pop_front();
        drv->drive(tx);
        scb->writeIn(tx);
        tick(tb, tfp);
        monOut->monitor();
    }
    scb->report();
    delete monOut;
    delete scb;
    delete drv;
    return finish(tb, tfp);
}

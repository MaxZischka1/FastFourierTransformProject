//implementing a transactional style testbench
#include <deque>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <random>
#include "verilatorTB.h"
#include <VSBM16.h>
#include <verilated.h>
#include <verilated_vcd_c.h>


//Transaction Item Input
class SBMTxIn{
    public:
        int16_t evRE, evIM, oddRE, oddIM;
        int16_t omgRE, omgIM;
};
//Transaction Item Output
class SBMTxOut{
    public:
        int16_t outRE, outIM;
};
//Transaction Item Generator(Random generator between 32767,-326718)
SBMTxIn* SBMTxGen(){
    SBMTxIn *tx = new SBMTxIn();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib1(-32768, 32767); 
    std::uniform_real_distribution<double> ang(0.0, 2.0 * M_PI);
    tx->evRE = distrib1(gen);
    tx->evIM = distrib1(gen);
    tx->oddRE = distrib1(gen);
    tx->oddIM = distrib1(gen);
    tx->omgRE = (int16_t)(cos(ang(gen))*32767.0);
    tx->omgIM = (int16_t)(sin(ang(gen))*32767.0);
    return tx;
};

//Input Driver
class SBMTxDrive{
    private:
        VSBM16 *dut;
    public:
        SBMTxDrive(VSBM16 *dut){
            this->dut = dut;
        }
        
        void drive(SBMTxIn *tx){
            dut->d1InRE = tx->oddRE;
            dut->d1InIM = tx->oddIM;
            dut->d2InRE = tx->evRE;
            dut->d2InIM = tx->evIM;
            dut->WInRE = tx->omgRE;
            dut->WInIM = tx->omgIM;
            delete tx;

        }
};

class SBM16Scb{
    private:
        std::deque<SBMTxIn*> in_q;
    public:
        void writeIn(SBMTxIn *tx){
            in_q.push_back(tx);
        }
        void writeOut(SBMTxOut *tx){
            if(in_q.empty()){
                std::cout << "Error SBMTxIN Empty" << std::endl;
                exit(1);
            }
            SBMTxIn *in;
            in = in_q.front();
            in_q.pop_front();
            int interRe = (in->oddRE*in->omgRE - in->oddIM * in->omgIM);
            int interIM = (in->oddRE*in->omgIM + in->oddIM*in->omgRE);
            int outRE = (interRe>>15)+in->evRE;
            int outIM = (interIM>>15)+in->evIM;

            if((outRE == tx->outRE) &&
            (outIM == tx->outIM))
        {
            std::cout << "TestBench Success" << std::endl;
        }else{
            std::cout <<"TestBench Error" <<std::endl;
            std::cout <<"Expected  outRE: "<<outRE<<"  outIM"<<outIM<<std::endl;
            std::cout<<"Actual   outRE: "<<tx->outRE<<" outIM: "<<tx->outIM<<std::endl;
            std::cout<<"Inputs     oddRE: "<<in->oddRE <<" oddIM: "<<in->oddIM<<" evRE: "   
            <<in->evRE<<" evIM: "<<in->evIM<<" omgRE: "<<in->omgRE<<" omgIM: "<<in->omgIM<<std::endl;
             std::cout <<"Sim Time: "<<main_time<<std::endl;
            error_count++;
        }
        delete in;
        delete tx;
        }
    };

//Monitor for TX
class SBM16MonIn{
    private:
        VSBM16 *dut;
        SBM16Scb *scb;
    public:
        SBM16MonIn(VSBM16 *dut,  SBM16Scb *scb){
            this->dut = dut;
            this->scb = scb;
        }

        void monitor(){
            SBMTxIn *tx = new SBMTxIn;
            tx->evRE = dut->d2InRE;
            tx->evIM = dut->d2InIM;
            tx->oddRE = dut->d1InRE;
            tx->oddIM = dut->d1InIM;
            tx->omgRE = dut->WInRE;
            tx->omgIM = dut->WInIM;
            scb->writeIn(tx);
        }
};



class SBM16MonOut{
    private:
        VSBM16 *dut;
        SBM16Scb *scb;
    public: 
        SBM16MonOut(VSBM16 *dut, SBM16Scb *scb){
            this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            SBMTxOut *tx = new SBMTxOut;
            tx->outRE = dut->dataOutRE;
            tx->outIM = dut->dataOutIM;
            scb->writeOut(tx);
        }
};



//Building writeOut that offloads inputs, does the operations and compares to dut output



int main(int argc, char** argv){
    VSBM16 *tb = new VSBM16;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_SBM16.vcd");
    SBMTxIn *tx;
    int max_time = 150;
    
    SBMTxDrive *drv = new SBMTxDrive(tb);
    SBM16Scb *scb = new SBM16Scb();
    SBM16MonIn *monIn = new SBM16MonIn(tb,scb);
    SBM16MonOut *monOut = new SBM16MonOut(tb,scb);

    for(int cycles = 0; cycles<max_time; cycles++){
        tx = SBMTxGen();
        drv->drive(tx);
        tick(tb,tfp);
        monIn->monitor();
        monOut->monitor();

        
    }
    delete monIn;
    delete monOut;
    delete scb;
    delete drv;
    return finish(tb,tfp);
    //make makefile tmwr
    
}

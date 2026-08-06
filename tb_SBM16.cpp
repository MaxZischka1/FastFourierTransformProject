//implementing a transactional style testbench
#include <deque>
#include <cstdint>
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
        int16_t outEvRE, outEvIM, outOddRE, outOddIM;
};
//Transaction Item Generator(Random generator between 32767,-326718)
SBMTxIn* SBMTxGen(){
    SBMTxIn *tx = new SBMTxIn();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib1(-32768, 32767); 
    std::uniform_real_distribution<double> ang(0, M_PI*2.0);
    int evRE = distrib1(gen);
    int evIM = distrib1(gen);
    int oddRE = distrib1(gen);
    int oddIM = distrib1(gen);
    bool evMag = (((int64_t)evRE*evRE + (int64_t)evIM*evIM)< 32767LL*32767LL);
    bool oddMag = (((int64_t)oddRE*oddRE + (int64_t)oddIM*oddIM)< 32767LL*32767LL);
    tx->evRE = evMag?evRE:0;
    tx->evIM = evMag?evIM:0;
    tx->oddRE = oddMag?oddRE:0;
    tx->oddIM = oddMag?oddIM:0;
    double angleGen = ang(gen);
    tx->omgRE = (cos(angleGen)*32767.0);
    tx->omgIM = (sin(angleGen)*32767.0);
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
            int sumEvRE = ((int)in->evRE+(int)in->oddRE)>>1;
            int sumEvIM = ((int)in->evIM+(int)in->oddIM)>>1;

            int interOddRE1 = (in->oddRE - in->evRE);
            int interOddIM1 = (in->oddIM - in->evIM);

            int64_t interOddRE2 = (int64_t)(interOddRE1*in->omgRE -  interOddIM1*in->omgIM);
            int64_t interOddIM2 = (int64_t)(interOddRE1*in->omgIM +  interOddIM1*in->omgRE);

            int sumOddRE = (int)(interOddRE2>>16);
            int sumOddIM = (int)(interOddIM2>>16);




            //TO DO: Implement full scoreboard and output.
        if
            ((sumEvRE==tx->outEvRE)&&(sumEvIM==tx->outEvIM)&&
            (sumOddRE==tx->outOddRE)&&(sumOddIM==tx->outOddIM)){
            std::cout << "TestBench Success" << std::endl;
        }else{
            std::cout <<"TestBench Error" <<std::endl;
            std::cout <<"Expected  outEvRE: "<<sumEvRE<<"  outEvIM:  "<<sumEvIM<<"  outOddRE:   "<<sumOddRE<<"  outOddIM:  "<<sumOddIM<<std::endl;
            std::cout<<"Actual  outEvRE: "<<tx->outEvRE<<"  outEvIM:  "<<tx->outEvIM<<"  outOddRE:   "<<tx->outOddRE<<"  outOddIM:  "<<tx->outOddIM<<std::endl;
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
            tx->outEvRE = dut->dOutEvRE;
            tx->outEvIM = dut->dOutEvIM;
            tx->outOddRE = dut->dOutOddRE;
            tx->outOddIM = dut->dOutOddIM;
            scb->writeOut(tx);
        }
};



//Building writeOut that offloads inputs, does the operations and compares to dut output



int main(int argc, char** argv){
    VSBM16 *tb = new VSBM16;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_SBM16.vcd");
    SBMTxIn *tx;
    int max_time = 1000;
    
    SBMTxDrive *drv = new SBMTxDrive(tb);
    SBM16Scb *scb = new SBM16Scb();
    SBM16MonIn *monIn = new SBM16MonIn(tb,scb);
    SBM16MonOut *monOut = new SBM16MonOut(tb,scb);

    for(int cycles = 0; cycles<max_time; cycles++){
        tx = SBMTxGen();
        drv->drive(tx);
        tick(tb,tfp);
        tick(tb,tfp);
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

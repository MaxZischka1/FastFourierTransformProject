//TO DO AFTER GDS PARSER. FILE READING NEEDS CHANGING
#include <deque>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <random>
#include "verilatorTB.h"
#include <VSBM16.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

int reset_cycles = 3;

//Transaction Item Input
class SBMTxIn{
    public:
        int16_t interOddRE1, interOddIM1;
        int16_t WInRE, WInIM;
        bool reset, en;
};
//Transaction Item Output
class SBMTxOut{
    public:
        int16_t dOutOddIM, dOutOddRE, validO;
};
//Try and load the queue here consult TB used in parser
//figure these out later
SBMTxIn* SBMTxGen(){
    SBMTxIn* tx = new SBMTxIn();
    std::ifstream inReal("inputsRE.hex");
    std::ifstream inImag("inputsIM.hex");
    inReal>>std::hex>>tx->interOddRE1;
    inReal>>std::hex>>tx->interOddIM1;
    tx->reset = 1;
    tx->en = 1;
    return tx;
};




std::deque<SBMTxIn*> SBMTxGenQueue(){
    std::deque<SBMTxIn*> seq;

    SBMTxIn* tx = new SBMTxIn();
    tx->reset = 0;
    tx->en = 0;
    tx->interOddIM1 = 0;
    tx->interOddRE1 = 0;
    seq.push_back(tx);


    for(int i = 0; i < 15; i++){
        SBMTxIn* tx = SBMTxGen();
        seq.push_back(tx);
    }

    // SBMTxIn* tx3 = new SBMTxIn();
    // tx->reset = 1;
    // tx->en = 1;
    // tx->interOddIM1 = 0;
    // tx->interOddRE1 = 0;
    // seq.push_back(tx3);

    return seq;

}

//Input Driver
class SBMTxDrive{
    private:
        VSBM16 *dut;
    public:
        SBMTxDrive(VSBM16 *dut){
            this->dut = dut;
        }
        
        void drive(SBMTxIn *tx){

            dut->interOddRE1 = tx->interOddRE1;
            dut->interOddIM1 = tx->interOddIM1;
            dut->en = tx->en;
            dut->reset = tx->reset;
            delete tx;

        }
};

int16_t WInREin[] = {0x7FFF, 0x7642, 0x5A82, 0x30FC, 0x0000, 0xCF04, 0xA57E, 0x89BE};
int16_t WInIMin[] = {0x0000, 0xCF04, 0xA57E, 0x89BE, 0x8000, 0x89BE, 0xA57E, 0xCF04};

int counter = 0;
class SBM16Scb{
    private:
        std::deque<SBMTxIn*> in_q;
    public:
        int sumOddRE;
        int sumOddIM;
        int WInRE;
        int WInIM;
        void writeIn(SBMTxIn *tx){
            in_q.push_back(tx);
        }
        void writeOut(SBMTxOut *tx){
            if(in_q.empty()){
                std::cout << "Error SBMTxIN Empty" << std::endl;
                exit(1);
            }
            SBMTxIn *in;
            if(!tx->validO){
                delete tx; 
                return;
            }//for pipelining
            WInRE = WInREin[counter];
            WInIM = WInIMin[counter];
            
            in = in_q.front();
            in_q.pop_front();

            if(in->en){
                if(counter == 7) counter = 0;
                else counter = counter + 1;   
            }
            if(!in->reset){
               sumOddRE = 0;
               sumOddIM = 0;
            }else if(in->en){
                int interOddRE1 = in->interOddRE1;
                int interOddIM1 = in->interOddIM1;

                int64_t interOddRE3 = (interOddRE1*WInRE -  interOddIM1*WInIM);
                int64_t interOddIM3 = (interOddRE1*WInIM +  interOddIM1*WInRE);

                sumOddRE = (int)(interOddRE3>>16);
                sumOddIM = (int)(interOddIM3>>16);
            }

        if
            ((sumOddRE==tx->dOutOddRE)&&(sumOddIM==tx->dOutOddIM)){
            std::cout << "TestBench Success" << std::endl;
            std::cout<<"Actaul  validO: "<<tx->validO<<std::endl;
        }else{
            std::cout <<"TestBench Error" <<std::endl;
            std::cout <<"Expected  sumOddRE: "<<sumOddRE<<"  sumOddIM:  "<<sumOddIM<<std::endl;
            std::cout<<"Actual  outRE: "<<tx->dOutOddRE<<"  outIM:  "<<tx->dOutOddIM<<std::endl;
            std::cout<<"Actaul  validO: "<<tx->validO<<std::endl;
            std::cout<<"Inputs     interRE: "<< in->interOddRE1 <<" oddIM: "<< in->interOddIM1
            <<" omgRE: "<<WInRE<<" omgIM: "<<WInIM<<std::endl;
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
            
            tx->interOddRE1 = dut->interOddRE1;
            tx->interOddIM1 = dut->interOddIM1;
            tx->en = dut->en;
            tx->reset = dut->reset;
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
            tx->dOutOddRE = dut->dOutOddRE;
            tx->dOutOddIM = dut->dOutOddIM;
            tx->validO = dut->validO;
            scb->writeOut(tx);
        }
};



//Building writeOut that offloads inputs, does the operations and compares to dut output



int main(int argc, char** argv){
    VSBM16 *tb = new VSBM16;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_SBM16.vcd");
    SBMTxIn *tx;
    int max_time = 8;
    
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
    
}

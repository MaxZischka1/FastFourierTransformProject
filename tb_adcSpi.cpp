#include <deque>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "verilatorTB.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VadcSpi.h>

bool tb_called = false;




std::vector<int> dataIn = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //each represents a half cycle of sclk
                           0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,0,0,0,
                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
std::vector<int> resetN = {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
std::vector<int> startTrans = {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int main_cycles = dataIn.size();

class ADCTxIn{
    public:
        bool startTrans, dataIn, resetN;
};

class ADCTxOut{
    public:
        int16_t dataOut;
        bool scss, validO;
        
};

std::deque<ADCTxIn*> genTx(){
    std::deque<ADCTxIn*> ins;
    for(int i = 0; i < main_cycles; i++){
        ADCTxIn *tx = new ADCTxIn();
        tx->dataIn = dataIn[i];
        tx->resetN = resetN[i];
        tx->startTrans = startTrans[i];
        ins.push_back(tx);
    }
    return ins;
};

class ADCDrive{
    private:
        VadcSpi *dut;
    public:
        ADCTxIn* tx = new ADCTxIn();
        ADCDrive(VadcSpi *dut){
            this->dut = dut;
        }
        void drive(ADCTxIn *tx){
            dut->startTrans = tx->startTrans;
            dut->dataIn = tx->dataIn;
            dut->resetN = tx->resetN;
        }
};

class ADCScb{
    private:
         std::deque<ADCTxIn*> in_q;
    public:

        int16_t sol = 0x0FED;
        

        void writeIn(ADCTxIn *tx){
            in_q.push_back(tx);
        }

        void writeOut(ADCTxOut *tx){
             if(in_q.empty()){
                std::cout <<"Queue empty." << std::endl;
                exit(1);
            }
            ADCTxIn* in;
            in = in_q.front();
            in_q.pop_front();

            if(tx->dataOut != sol){
                std::cout << "FAILED" << std::endl;
                std::cout << "DUT Output:   " << tx->dataOut << std::endl;
                std::cout << "Testbench Sol:   " << sol << std::endl;
                error_count++;
            }else{
                std::cout << "SUCCESS"<< std::endl;
                std::cout << "output:  " << tx->dataOut << std::endl;
            }
        }

};

class ADCmonIn{
    private:
        VadcSpi *dut;
        ADCScb* scb;
    public:

    ADCmonIn(VadcSpi *dut, ADCScb* scb){
        this->dut = dut;
        this->scb = scb;
    }
    void monitor(){
        ADCTxIn* tx = new ADCTxIn();

        tx->startTrans = dut->startTrans;
        tx->dataIn = dut->dataIn;
        tx->resetN = dut->resetN;
        scb->writeIn(tx);
    }
};

class ADCmonOut{
    private:
        VadcSpi *dut;
        ADCScb* scb;
    public:

    ADCmonOut(VadcSpi *dut, ADCScb* scb){
        this->dut = dut;
        this->scb = scb;
    }
    void monitor(){
        if(dut->validO == 1){
            ADCTxOut* tx = new ADCTxOut();
            tb_called = true;
            tx->scss = dut->scss;
            tx->dataOut = dut->dataOut;
            tx->validO = dut->validO;
            scb->writeOut(tx);
        }
    }
};


int main(int argc, char** argv){
    VadcSpi *tb = new VadcSpi;
    VerilatedVcdC *tfp = new VerilatedVcdC;
     setup(tb, tfp, argc, argv, "waveform_spi.vcd");
    ADCTxIn *tx;
    std::deque<ADCTxIn*> in = genTx();
    ADCDrive *drv = new ADCDrive(tb);
    ADCScb *scb = new ADCScb();

    ADCmonIn *monIn = new ADCmonIn(tb, scb);
    ADCmonOut *monOut = new ADCmonOut(tb, scb);

     for(int i = 0; i < main_cycles; i++){
        if(in.empty()){ std::cout << "Error inputs Empty" << std::endl; exit(1);}
        tx = in.front();
        in.pop_front();
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
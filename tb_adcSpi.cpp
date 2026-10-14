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

int sclkPeriod = 279;
std::vector<int> dataIn     = {0,0,0,0,0,0,
                                1,1,1,1,1,1,1,0,1,1,0,1, 
                                0,0,
                                0,0,0,0,0,0,
                                1,1,0,1,1,1,1,0,1,1,1,1, 
                                0,0};
std::vector<int> resetN     = {0,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,1,1,1,1,
                                 1,1,
                                0,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,1,1,1,1,
                                 1,1};
std::vector<int> startTrans = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; //probably how it is implemented for Audio Equil

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
        for(int j = 0; j < sclkPeriod; j++){
            ADCTxIn *tx = new ADCTxIn();
            tx->dataIn = resetN[i] ? dataIn[i] : 0;
            tx->resetN = resetN[i];
            tx->startTrans = startTrans[i];
            ins.push_back(tx);
        }
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
            delete tx;
        }
};

class ADCScb{
    private:
         std::deque<ADCTxIn*> in_q;
    public:

        int16_t sol[2] = {0x0FED, 0x0DEF};
        int out_count = 0;

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

            if(tx->dataOut != sol[out_count]){
                std::cout << "FAILED" << std::endl;
                std::cout << "DUT Output:   " << std::hex << tx->dataOut << std::dec << std::endl;
                std::cout << "Testbench Sol:   " << std::hex << sol[out_count] << std::dec << std::endl;
                error_count++;
            }else{
                std::cout << "SUCCESS"<< std::endl;
                std::cout << "output:  " << std::hex << tx->dataOut << std::dec << std::endl;
            }
            out_count++;
            delete in;
            delete tx;
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
    if(main_cycles != (int)resetN.size() || main_cycles != (int)startTrans.size())
        std::cout << "inputs don't match time *ERROR*" << std::endl;
    ADCTxIn *tx;
    std::deque<ADCTxIn*> in = genTx();
    int total_ticks = in.size();
    ADCDrive *drv = new ADCDrive(tb);
    ADCScb *scb = new ADCScb();

    ADCmonIn *monIn = new ADCmonIn(tb, scb);
    ADCmonOut *monOut = new ADCmonOut(tb, scb);

     for(int i = 0; i < total_ticks; i++){
        if(in.empty()){ std::cout << "Error inputs Empty" << std::endl; exit(1);}
        tx = in.front();
        in.pop_front();
        drv->drive(tx);
        tick(tb,tfp);
        monIn->monitor();
        monOut->monitor();
    }
    if(!tb_called) std::cout << "validO never asserted *ERROR*" << std::endl;
    delete monIn;
    delete monOut;
    delete scb;
    delete drv;
    return finish(tb,tfp);
}

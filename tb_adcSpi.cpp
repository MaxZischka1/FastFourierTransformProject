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

class ADCTxIn{
    public:
        bool startTrans, dataIn, resetN;
};

class ADCTxOut{
    public:
        int16_t dataOut;
        bool scss, validO;
        
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

};

class ADCmonIn{
    private:
        VadcSpi *dut;
        ADCTxIn* tx;
    public:

    ADCmonIn(VadcSpi *dut, ADCTxIn* tx){
        this->dut = dut;
        this->tx = tx;
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
        ADCTxIn* tx;
    public:

    ADCmonIn(VadcSpi *dut, ADCTxIn* tx){
        this->dut = dut;
        this->tx = tx;
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

}
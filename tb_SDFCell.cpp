#include <deque>
#include <cmath>
#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include "verilatorTB.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VSDFCell.h>


int reset[] = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int valid[] = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0};

bool tb_called = false;




class TxInSDF{
    public:
        int16_t dataInRE, dataInIM;
        bool valid, reset;
};

class TxOutSDF{
    public:
        int16_t dataOutRE, dataOutIM;
        bool validOut;
};
std::ifstream inRealHex("inputsRE.hex");
std::ifstream inImagHex("inputsIM.hex");
std::ifstream wRealHex("twiddleRE.hex");
std::ifstream wImagHex("twiddleIM.hex");
std::vector<uint32_t> inRe, inIm, wRe, wIm;
uint32_t reI,imI,reW,imW;
void formatIns(){
    while (inRealHex >> std::hex >> reI && inImagHex >> std::hex >> imI) {
    inRe.push_back(reI);
    inIm.push_back(imI);
    }
while (wRealHex >> std::hex >> reW && wImagHex >> std::hex >> imW) {
    wRe.push_back(reW);
    wIm.push_back(imW);
}
};

std::deque<TxInSDF*> TxSDFGen(){
    std::deque<TxInSDF*> seq;
    int cycles = 28;
    formatIns();
    int dataIndx = 0;
    for(int i = 0; i < cycles; i++){
        TxInSDF* tx = new TxInSDF();
        if(valid[i]){
            tx->dataInRE = (int16_t)inRe[dataIndx];
            tx->dataInIM = (int16_t)inIm[dataIndx];
            dataIndx++;
        } else{
            tx->dataInRE = 0x7FFF;
            tx->dataInIM = 0x7FFF;
        }
        tx->valid = valid[i];
        tx->reset = reset[i];
        seq.push_back(tx);
    }
    return seq;
};

class SDFTxDrive {
    private:
        VSDFCell *dut;
    public:
        TxInSDF* tx = new TxInSDF();

        SDFTxDrive(VSDFCell *dut){
            this->dut = dut;
        }
        void drive(TxInSDF *tx){
            dut->dataInRE = tx->dataInRE;
            dut->dataInIM = tx->dataInIM;
            dut->valid = tx->valid;
            dut->reset = tx->reset;
            delete tx;
        }
        
};


class SDFScb{
    private:
        std::deque<TxInSDF*> in_q;
    public:
        void writeIn(TxInSDF *tx){
            in_q.push_back(tx);
        }
        std::deque<int16_t> dataOutQRE;
        std::deque<int16_t> dataOutQIM;
        
        void generateRef(){
            for(int i = 0; i < 4; i++){
                int dataOutEvSCBREInt = (int16_t)inRe[i] + (int16_t)inRe[i+4];
                int dataOutEvSCBIMInt = (int16_t)inIm[i] + (int16_t)inIm[i+4];
                int16_t dataOutEvSCBRE = int16_t(dataOutEvSCBREInt>>1);
                int16_t dataOutEvSCBIM = int16_t(dataOutEvSCBIMInt>>1);

                dataOutQRE.push_back(dataOutEvSCBRE);
                dataOutQIM.push_back(dataOutEvSCBIM);
            }
            for(int i = 0; i < 4; i++){
                int dataOutOddSCBRE = (int16_t)inRe[i] - (int16_t)inRe[i+4];
                int dataOutOddSCBIM = (int16_t)inIm[i] - (int16_t)inIm[i+4];
                int16_t WInRE = (int16_t)wRe[i];
                int16_t WInIM = (int16_t)wIm[i];
                int64_t interOddRE3 = ((dataOutOddSCBRE>>1)*WInRE -  (dataOutOddSCBIM>>1)*WInIM);
                int64_t interOddIM3 = ((dataOutOddSCBRE>>1)*WInIM +  (dataOutOddSCBIM>>1)*WInRE);

                int16_t sumOddRE = (int16_t)(interOddRE3>>15);
                int16_t sumOddIM = (int16_t)(interOddIM3>>15);

                dataOutQRE.push_back(sumOddRE);
                dataOutQIM.push_back(sumOddIM);
            }
        }
        SDFScb(){
            generateRef();
        }

        void writeOut(TxOutSDF *tx){
            if(in_q.empty()){
                std::cout <<"Queue empty." << std::endl;
                exit(1);
            }
            
            TxInSDF* in;
            in = in_q.front();
            in_q.pop_front();
            
                if(dataOutQRE.front()==tx->dataOutRE){
                    std::cout << "Data Real success" << std::endl;
                    std::cout << "Data Real Value: " << tx->dataOutRE << std::endl;
                }
                else {
                    std::cout << "Data Real failed" << std::endl;
                    std::cout << "Data Real Value DUT: " << tx->dataOutRE << "Data Real Value TB: " << dataOutQRE.front() << std::endl;
                    error_count++;
                }
                if(dataOutQIM.front()==tx->dataOutIM){
                    std::cout << "Data Imag success" << std::endl;
                    std::cout << "Data Imag Value: " << tx->dataOutIM << std::endl;
                }
                else {
                    std::cout << "Data Imag failed" << std::endl;
                    std::cout << "Data Imag Value DUT: " << tx->dataOutIM << "Data Real Value TB: " << dataOutQIM.front() << std::endl;
                    error_count++;
                }
                dataOutQRE.pop_front();
                dataOutQIM.pop_front();
                delete in;
                delete tx; 
            }
       
     
    
};
class monOutSDF{
    private:
        VSDFCell *dut;
        SDFScb *scb;
    public:
        monOutSDF(VSDFCell *dut,  SDFScb *scb){
        this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            if (dut->validOut == 1) {
            tb_called = true;
            TxOutSDF *tx = new TxOutSDF();
            tx->dataOutRE = dut->dataOutRE;
            tx->dataOutIM = dut->dataOutIM;
            tx->validOut = dut->validOut;
            scb->writeOut(tx);
        }
    }
};  

class monInSDF{
    private:
        VSDFCell *dut;
        SDFScb *scb;
    public:
        monInSDF(VSDFCell *dut,  SDFScb *scb){
            this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            TxInSDF *tx = new TxInSDF();
            tx->dataInRE = dut->dataInRE;
            tx->dataInIM = dut->dataInIM;
            tx->valid = dut->valid;
            tx->reset = dut->reset;
            scb->writeIn(tx);
        }
};



int main(int argc, char** argv){
    VSDFCell *tb = new VSDFCell;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_SDFCell.vcd");
    TxInSDF *tx;
    int main_cycles = 28;

    SDFTxDrive *drv = new SDFTxDrive(tb);
    formatIns();
    SDFScb *scb = new SDFScb();
    monInSDF *monIn = new monInSDF(tb, scb);
    monOutSDF *monOut = new monOutSDF(tb, scb);

    std::deque<TxInSDF*> in = TxSDFGen();
    for(int i = 0; i<main_cycles; i++){
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



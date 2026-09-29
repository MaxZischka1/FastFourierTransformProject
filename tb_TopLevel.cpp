#include <deque>
#include <cmath>
#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include "verilatorTB.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VTopLevel.h>

std::vector<int> reset = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
std::vector<int> valid = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint16_t main_cycles = 50;
bool tb_called = false;




class TxInTL{
    public:
        int16_t dataInRE, dataInIM;
        bool valid, reset;
};

class TxOutTL{
    public:
        int16_t dataOutRE, dataOutIM;
        bool validOut;
};

std::ifstream inRealHex("inputsRE.hex");
std::ifstream inImagHex("inputsIM.hex");
std::ifstream wRealHex("twiddleRE.hex");
std::ifstream wImagHex("twiddleIM.hex");
std::vector<int16_t> inRe, inIm, wRe, wIm;
uint32_t reI,imI,reW,imW;

void formatIns(){
    while (inRealHex >> std::hex >> reI && inImagHex >> std::hex >> imI) {
    inRe.push_back((int16_t)(reI));
    inIm.push_back((int16_t)imI);
    }
while (wRealHex >> std::hex >> reW && wImagHex >> std::hex >> imW) {
    wRe.push_back((int16_t)reW);
    wIm.push_back((int16_t)imW);
}
};

std::deque <TxInTL*> TxTLGen(){
    std::deque<TxInTL*> seq;
    formatIns();
    int dataIndx = 0;
    for(int i = 0; i < main_cycles; i++){
        TxInTL* tx = new TxInTL();
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

//scoreboard

class TLScb{
    private:
        std::deque<TxInTL*> in_q;
    public:
        std::deque<int16_t> dataOutQRE;
        std::deque<int16_t> dataOutQIM;
        void generateRef(){
            int dataAddOutREInt, dataAddOutIMInt; //pre bit shift
            int16_t dataAddOutRE, dataAddOutIM; //pre bit shift
            int dataSubOutREInt, dataSubOutIMInt; //pre bit shift
            int16_t dataSubOutRE, dataSubOutIM; //pre bit shift

            int dataMultOutREInt, dataMultOutIMInt;
            int16_t dataMultOutRE, dataMultOutIM;
            int index;
            for(int i = 16; i >= 2; i /= 2){
                int half = i/2;
                for(int k = 0; k < 16; k += i){
                    for(int j = 0; j<half; j++){
                        index = j*(16/i);
                        dataAddOutREInt = (inRe[k+j] + inRe[k+j+half]);
                        dataAddOutIMInt = inIm[k+j] + inIm[k+j+half];
                        dataAddOutRE = (int16_t)(dataAddOutREInt>>1);
                        dataAddOutIM = (int16_t)(dataAddOutIMInt>>1);
                        //subtraction
                        dataSubOutREInt = (inRe[k+j] - inRe[k+j+half]);
                        dataSubOutIMInt = inIm[k+j] - inIm[k+j+half];
                        dataSubOutRE = (int16_t)(dataSubOutREInt>>1);
                        dataSubOutIM = (int16_t)(dataSubOutIMInt>>1);
                        //multiplication
                        if(i == 2){
                            dataMultOutRE = dataSubOutRE;
                            dataMultOutIM = dataSubOutIM;
                        } else if(i == 4){
                            if(index == 0){
                                dataMultOutRE = dataSubOutRE;
                                dataMultOutIM = dataSubOutIM;
                            } else {
                                dataMultOutRE = dataSubOutIM;
                                dataMultOutIM = -dataSubOutRE;
                            }
                        } else {
                            dataMultOutREInt = dataSubOutRE*wRe[index] - dataSubOutIM*wIm[index];
                            dataMultOutIMInt = dataSubOutRE*wIm[index] + dataSubOutIM*wRe[index];

                            dataMultOutRE = (int16_t)(dataMultOutREInt>>15);
                            dataMultOutIM = (int16_t)(dataMultOutIMInt>>15);
                        }

                        inRe[k+j] = dataAddOutRE;
                        inIm[k+j] = dataAddOutIM;

                        inRe[k+j+half] = dataMultOutRE;
                        inIm[k+j+half] = dataMultOutIM;
                    }
                }
            }
            for (int n = 0; n < 16; n++) {
                dataOutQRE.push_back(inRe[n]);
                dataOutQIM.push_back(inIm[n]);
            }
        }
        TLScb(){
            generateRef();
        }

        void writeIn(TxInTL* tx){
            in_q.push_back(tx);
        }

        void writeOut(TxOutTL* tx){
            if(in_q.empty()){
                std::cout <<"Queue empty." << std::endl;
                exit(1);
            }
            
            TxInTL* in;
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

//drivers
class TLTxDrive {
    private:
        VTopLevel *dut;
    public:
        TxInTL *tx = new TxInTL();

        TLTxDrive(VTopLevel *dut){
            this->dut = dut;
        }

        void drive(TxInTL *tx){
            dut->dataInRE = tx->dataInRE;
            dut->dataInIM = tx->dataInIM;
            dut->valid = tx->valid;
            dut->reset = tx->reset;
            delete tx;
        }
};

//monitors
class monInTL{
    private:
        VTopLevel *dut;
        TLScb *scb;

    public:
        monInTL(VTopLevel *dut,TLScb *scb){
            this->dut = dut;
            this->scb = scb;
        }
        void monitor(){
            TxInTL* tx = new TxInTL();
            tx->dataInRE = dut->dataInRE;
            tx->dataInIM = dut->dataInIM;
            tx->valid = dut->valid;
            tx->reset = dut->reset;
            scb->writeIn(tx);
        }

};

//monitors
class monOutTL{
    private:
        VTopLevel *dut;
        TLScb *scb;
    public:
        monOutTL(VTopLevel *dut,TLScb *scb){
            this->dut = dut;
            this->scb = scb;
        }

        void monitor(){
            if(dut->validOut == 1){
                tb_called = true;
                TxOutTL* tx = new TxOutTL();
                tx->dataOutRE = dut->dataOutRE;
                tx->dataOutIM = dut->dataOutIM;
                tx->validOut = dut->validOut;
                scb->writeOut(tx);
            }
        }
        
};

int main(int argc, char** argv){
    VTopLevel *tb = new VTopLevel;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_TopLevel.vcd");
    if(main_cycles != valid.size() || main_cycles != reset.size()) 
        std::cout << "inputs don't match time *ERROR*" << std::endl;
    TxInTL *tx;
    formatIns();
    std::deque<TxInTL*> in = TxTLGen();
    TLTxDrive *drv = new TLTxDrive(tb);
    TLScb *scb = new TLScb();

    monInTL *monIn = new monInTL(tb, scb);
    monOutTL *monOut = new monOutTL(tb, scb);

    

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
};
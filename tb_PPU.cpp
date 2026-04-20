#include <stdlib.h>
#include "VPPU.h"
#include "verilatorTB.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv){
    VPPU *tb = new VPPU;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_PPU.vcd");
    tb->startSigIN = 0;
    tb->clk = 0;

    int max_cycle = 600;
    for(int cycle = 0; (cycle < max_cycle) && !Verilated::gotFinish(); cycle++){
        if(cycle==1) tb->startSigIN = 1;
        if(cycle==2) tb->startSigIN = 0;
        tick(tb,tfp);
        if(cycle>=2 && cycle<= 9){ //behavior is indexing from 1 -8
            int expects = cycle-1;
            check("writeEnable1", tb->weADDRen1, 1, cycle);
            check("changeVal", tb->change, 0, cycle);
            check("InputBridgeAddress", tb->waddr1, expects, cycle);
        }
        if(cycle>=10 && cycle<= 11){//10 Sig goes high, 11 state is READ1, 12 is incrementing
            check("Done", tb->change, 1, cycle);
            check("readADDR2Buf", tb->weADDRen2, 0, cycle);
        }
        if(cycle>=12 && cycle <= 19){
            int expects = cycle-11;
            check("readADDR2Buf", tb->raddr1, expects, cycle);
        }
        if(cycle>=14&&cycle<=21){ //Pipelined twice
            int expects = cycle-13;
            check("write2Addr", tb->waddr2, expects, cycle);
            check("writeEnable2", tb->weADDRen2, 1, cycle);
        }
        
    }
    //
    return finish(tb,tfp);
}
//We haven't been doing write don't use 2's complement use Q1.15
#include <cstdint>
#include <cmath>
#include "verilatorTB.h"
#include "VBFU.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv){
    VBFU *tb = new VBFU;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_BFU.vcd");

    // int dInREEvArr[]

    int max_cycles = 50;
    tb->clk = 0;
    int16_t dInREEv = 0x7FFF;
    int16_t dInREOdd = 0x7FFF;
    int32_t dInIMEv = 0x0005A81;
    int32_t dInIMOdd = 0x00004000;
    int32_t wRE = 0x00000000;
    int32_t wIM = 0x00007FFF;

    for(int cycle = 0; (cycle<max_cycles)&&!Verilated::gotFinish(); cycle++){
        //Just sim some calculations
        tb->dInREEv=dInREEv;
        tb->dInREOdd=dInREOdd;
        tb->dInIMEv=dInIMEv;
        tb->dInIMOdd=dInIMOdd;
        tb->wRE=wRE;
        tb->wIM=wIM;
        tick(tb,tfp);
        if(cycle==0){ 
            check("BFU EMPTY", tb->dOutREEv, 0, cycle);
            check("BFU EMPTY", tb->dOutREOdd, 0, cycle);
            check("BFU EMPTY", tb->dOutIMEv, 0, cycle);
            check("BFU EMPTY", tb->dOutIMOdd, 0, cycle);
        }
        if(cycle==1){ 
            check("BFU OCCUPIED", tb->dOutREOdd, 0x4000, cycle);
        }
        if(cycle==2){ 
            check("BFU OCCUPIED", tb->dOutREOdd, 0x10, cycle);
        }
    }

    return finish(tb, tfp);
}
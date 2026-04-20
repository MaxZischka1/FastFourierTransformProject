#include <stdlib.h>
#include "verilatorTB.h"
#include "VTopLevel.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv){
    VTopLevel *tb = new VTopLevel;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv,"waveform_TopLevel.vcd");

    tb->startSig = 0;
    tb->clk = 0;
    int max_cycles = 150;
    for(int cycle = 0; (cycle < max_cycles) && !Verilated::gotFinish(); cycle++){
        if (cycle == 1) tb->startSig = 1;
        if (cycle == 2) tb->startSig = 0;
        int ram1Out =  tb->ram1Output;
        int inputBridgeOut = tb->waddr1Out;
        tick(tb, tfp);
        if(cycle >= 3 && cycle <= 10){//DO NOT CHANGE UNLESS VERY IMPORTANT
            int expectRam1 = cycle-2;
            int expectIB = expectRam1 - 1;
            check("ram1Outputs",ram1Out, expectRam1, cycle);
            check("inputBridgeOutputs", inputBridgeOut, expectIB, cycle);
        }
    }
    return finish(tb,tfp);
}



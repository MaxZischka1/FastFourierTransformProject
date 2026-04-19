#include <stdlib.h>
#include "verilatorTB.h"
#include "VTopLevel.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv){
    Verilated::commandArgs(argc,argv);
    Verilated::traceEverOn(true); 
    VTopLevel *tb = new VTopLevel;
    VerilatedVcdC* tfp = new VerilatedVcdC;

    tb->trace(tfp, 99);        
    tfp->open("waveformTopLevel.vcd");
    tb->startSig = 0;
    tb->clk = 0;
    int max_cycles = 15;
    for(int cycle = 0; (cycle < max_cycles) && !Verilated::gotFinish(); cycle++){
        if (cycle == 2) tb->startSig = 1;
        if (cycle == 3) tb->startSig = 0;
        int ram1Out =  tb->ram1Output;
        int inputBridgeOut = tb->waddr1Out;
        tick(tb, tfp);
        if(cycle >= 4 && cycle <= 11){
            int expectRam1 = cycle-3;
            check("ram1Outputs",ram1Out, expectRam1, main_time);
            check("inputBridgeOutputs", inputBridgeOut, expectRam1, main_time);
        }
    }
    evalEnd(error_count);
    // if (error_count == 0)
    // {
    //     printf("PassedTB");
    // } else{
    //     printf("Failed with %d error\n", error_count);
    // }
    tb->final();
    tfp->close();
    return (error_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}



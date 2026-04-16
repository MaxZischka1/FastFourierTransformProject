#include <stdlib.h>
#include "VTopLevel.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

static int main_time = 0;

void tick(VTopLevel *tb, VerilatedVcdC *tfp){
    tb->clk = 0;
    tb->eval();
    tfp->dump(main_time);
    main_time += 5;

    tb->clk = 1;
    tb->eval();
    tfp->dump(main_time);
    main_time += 5;
    
    tb->clk = 0;
    tb->eval();
    tfp->dump(main_time);
}

int main(int argc, char** argv){
    Verilated::commandArgs(argc,argv);
    Verilated::traceEverOn(true); 
    VTopLevel *tb = new VTopLevel;
    VerilatedVcdC* tfp = new VerilatedVcdC;

    tb->trace(tfp, 99);        
    tfp->open("waveform.vcd");
    tb->startSig = 0;
    tb->clk = 0;
    int max_cycles = 10000;
    for(int cycle = 0; (cycle < max_cycles) && !Verilated::gotFinish(); cycle++){
        if (cycle == 2) tb->startSig = 1;
        if (cycle == 3) tb->startSig = 0;

        tick(tb, tfp);
    }
    tb->final();
    tfp->close();
    exit(EXIT_SUCCESS);
}



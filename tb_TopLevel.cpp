#include <stdlib.h>
#include "VTopLevel.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

static int main_time = 0;
static int error_count = 0;

void tick(VTopLevel *tb, VerilatedVcdC *tfp){
    tb->clk = 0;
    tb->eval();
    tfp->dump(main_time);
    main_time += 5;

    tb->clk = 1;
    tb->eval();
    tfp->dump(main_time);
    main_time += 5;
    
}

void check(const char* name, int actual, int expected, int cycle){
    if(actual != expected){
        printf("Failure cycle %d: %s = 0x%04X, expected 0x%04X\n",
                cycle, name, actual, expected);

        error_count++;
    }
}

int main(int argc, char** argv){
    Verilated::commandArgs(argc,argv);
    Verilated::traceEverOn(true); 
    VTopLevel *tb = new VTopLevel;
    VerilatedVcdC* tfp = new VerilatedVcdC;

    tb->trace(
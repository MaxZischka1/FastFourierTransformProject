#include <stdlib.h>
#include "VTopLevel.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv){
    Verilated::commandArgs(argc,argv);
    Verilated::traceEverOn(true); 
    VTopLevel *tb = new VTopLevel;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    tb->trace(tfp, 99);        
    tfp->open("waveform.vcd");
    tb->startSig = 0;

    int main_time = 0;
    int max_time = 10000000;
    
    while(!Verilated::gotFinish() && main_time<max_time){
        if((main_time%5) == 0){
            tb->clk = !tb-> clk;
        }
        if((main_time)==20){
            tb->startSig = 1;
        }
        if((main_time)==25) tb->startSig = 0;
        tb->eval();
        tfp->dump(main_time);
        main_time++;
    }
    tb->final();
    tfp->close();
    exit(EXIT_SUCCESS);
}
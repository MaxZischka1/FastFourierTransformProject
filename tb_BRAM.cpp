#include <stdlib.h>
#include "VBRAM.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

static int main_time = 0;
static int error_count = 0;

void tick(VBRAM *tb, VerilatedVcdC *tfp){
    tb->clk=0;
    tb->eval();
    tfp->dump(main_time);
    main_time += 5;

    tb->clk=1;
    tb->eval();
    tfp->dump(main_time);
    main_time += 5;
}

void check(const char* name, int actual, int expected, int cycle){
    if(actual != expected){
        printf("Failed at cycle %d: %s = 0x%04X, expected0x%04X\n" ,
        cycle, name, actual, expected);
        error_count++;
    }
}
int main (int argc, char** argv){
    Verilated::commandArgs(argc,argv);
    Verilated::traceEverOn(true);
    VBRAM *tb = new VBRAM;
    VerilatedVcdC *tfp = new VerilatedVcdC;

    tb->trace(tfp,99);
    tfp->open("waveform_bram.vcd");

    for(int i = 0; i < 8; i++){
        tb->we=1;
        tb->waddr = i;
        tb->wdata = (5+i);
        tick(tb, tfp);
    }

    for(int j = 0; j<8; j++){
        
        tb->we=0;
        tb->raddr = j;
        tick(tb, tfp);
        check("bramRaddr", tb->rdata, (5+j), main_time);
    }
    if(error_count==0){
        printf("PassedTB");
    }else{
        printf("Failed with %d errors", error_count);
    }
    tb->final();
    tfp->close();
    return (error_count == 0)? EXIT_SUCCESS:EXIT_FAILURE;
}
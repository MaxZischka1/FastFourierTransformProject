#include <stdlib.h>
#include "VBRAM.h"
#include "verilatorTB.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main (int argc, char** argv){
    VBRAM *tb = new VBRAM;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv,"waveform_bram.vcd");
    tb->we=1;
    tb->waddr = 0;
    tb->wdata = (5);
    tb->eval();

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
        check("bramRaddr", tb->rdata, (5+j), j);
    }
    return finish(tb,tfp);
}
//Agrees with premise I already had in top level. Data need to be present one clock cycle before
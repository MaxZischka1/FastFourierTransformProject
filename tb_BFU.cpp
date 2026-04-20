#include <stdlib.h>
#include "verilatorTB.h"
#include "VBFU.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv){
    VBFU *tb = new VBFU;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv);

    int max_cycles = 50;

    for(int cycle = 0; (cycle<max_cycles)&&!Verilated::gotFinish(); cycle++){
        //Just sim some calculations
    }

    return finish(tb, tfp);
}
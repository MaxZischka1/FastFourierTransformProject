#ifndef VERILATORUSING
#define VERILATORUSING
#include "verilated.h"
#include "verilated_vcd_c.h"

extern int main_time;
extern int error_count;

template <typename T>
void tick(T *tb, VerilatedVcdC *tfp){ 
    tb->clk = 1;
    tb->eval();
    tfp->dump(main_time);
    main_time += 5;

    tb->clk = 0;
    tb->eval();
    tfp->dump(main_time);
    main_time += 5;
}

template <typename TB, typename TV>
void setup(TB *tb, TV *tfp, int argc, char** argv, const char* waveName){
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    tb->trace(tfp,99);
    tfp->open(waveName);
}

void check(const char *name, int actual, int expected, int time);

template <typename TB1, typename TV1>
int finish(TB1 *tb, TV1 *tfp){
    tb->final();
    tfp->close();
    if(error_count==0){
        printf("PassedTB\n");
    }else{
        printf("Failed with %d errors\n", error_count);
    }
    delete tb;
    delete tfp;
    return (error_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

#endif
/*NOTES:
We are implementing the tick in the header file because if we didn't then there would be a 
call to tick(T, VerilatedVcdC) or we would have to write out every object type that could 
be passed tick meaning every testbench we plan to create. The compiler deals with this
and does not cause a multiple definitions error. Extern just means it needs to be implemented
in the cpp file. ifndef is also dealing with multiple declarations and errors.
*/

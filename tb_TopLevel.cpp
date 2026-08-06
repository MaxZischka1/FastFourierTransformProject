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
    int inputBridgeEven = 0;
    int inputBridgeOdd = 1;
    int max_cycles = 150;
    for(int cycle = 0; (cycle < max_cycles) && !Verilated::gotFinish(); cycle++){
        if (cycle == 1) tb->startSig = 1;
        if (cycle == 2) tb->startSig = 0;
        int ram1OutEv =  tb->ram1OutputEvO;
        int ram1OutOdd =  tb->ram1OutputOddO;
        int inputBridgeOutEv = tb->ramEvAdd;
        int inputBridgeOutOdd = tb->ramOddAdd;
        int ramAddressIn = tb->waddr1Out;

        tick(tb, tfp);
        if(cycle >= 3 && cycle <= 6){
            int ramAddressExp = cycle-3;
            int inBridgeRevEv = (inputBridgeEven&4)>>2 | (inputBridgeEven&2) | (inputBridgeEven&1)<<2;
            int inBridgeRevOdd = (inputBridgeOdd&4)>>2 | (inputBridgeOdd&2) | (inputBridgeOdd&1)<<2;
            check("ram1OutputEv",ram1OutEv, ramAddressExp, cycle);
            check("ram1OutputOdd",ram1OutOdd, ramAddressExp, cycle);
            check("inputBridgeEven", inputBridgeOutEv, inBridgeRevEv, cycle);
            check("inputBridgeOdd", inputBridgeOutOdd, inBridgeRevOdd, cycle);
            check("ramAddressIn", ramAddressIn, ramAddressExp, cycle);
            inputBridgeEven = inputBridgeEven+2;
            inputBridgeOdd = inputBridgeOdd+2;
        }
        if(cycle >= 8 && cycle <= 11){
            int expectedRaddr1 = cycle - 8;
            check("raddr1",tb->raddr1Out, expectedRaddr1, cycle);
        }
        if(cycle >= 9 && cycle <= 12){ //1 clock cycle from address to data presented
            int expectedRamData = cycle - 9;
            check("BFUInput", tb->readMemSelOut, 0, cycle);
            check("Read Data Real Even",tb->rdata1REOEv, expectedRamData, cycle);
            check("Read Data Real Odd",tb->rdata1REOOdd, expectedRamData, cycle);
        }
        if(cycle >= 12 && cycle <= 15){
            int twiddleRE = tb->omgREOut;
            int twiddleIM = tb->omgIMOut;
            int expectInputRE = cycle-12;
            int expectInputIM = 0;
            int expectBFUREEvOut = (expectInputRE+expectInputRE)>>1;
            int expectBFUIMEvOut = (expectInputIM+expectInputIM)>>1;

            int expectBFUREOddOutInt1 = (expectInputRE - expectInputRE);
            int expectBFUIMOddOutInt1 = (0 - 0);
            int64_t interOddRE2 = (int64_t)(expectBFUREOddOutInt1*twiddleRE -  expectBFUIMOddOutInt1*twiddleIM);
            int64_t interOddIM2 = (int64_t)(expectBFUREOddOutInt1*twiddleIM +  expectBFUIMOddOutInt1*twiddleRE);
            int sumOddRE = (int)(interOddRE2>>16);
            int sumOddIM = (int)(interOddIM2>>16);
            check("BFUOutput Even Real", tb->BFUREoutEvO, expectBFUREEvOut, cycle);
            check("BFUOutput Odd Real", tb->BFUREoutOddO, sumOddRE, cycle);
            check("BFUOutput Even Imag", tb->BFUIMoutEvO, expectBFUIMEvOut, cycle);
            check("BFUOutput Odd Imag", tb->BFUIMoutOddO, sumOddIM, cycle);
        }
        if(cycle >= 13 && cycle <= 16){
            int expectedwaddr1 = cycle-13;
            check("waddr2",tb->waddr2Out, expectedwaddr1, cycle);
        }
        if(cycle >= 13 && cycle <= 16){
            int expectedwaddr1 = cycle-13;
            check("raddr2",tb->waddr2Out, expectedwaddr1, cycle);
        }




    }
    return finish(tb,tfp);
}



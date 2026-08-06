//We made the PPU wrong the logic of testbench eeprom is just wrong
//Idea is to keep the counters that add by two and address that loads by 1
//So just change the odd to also add by two. And have both reverse there signal
#include <stdlib.h>
#include <iostream>
#include <random>
#include <deque>
#include "VPPU.h"
#include "verilatorTB.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

/*
-----Flow of the address generator so far---
A layer between the BRAM and PPU for decoder will be needed most likely clocked to not create the crit path.

IDLE UNTIL Start sign
CYCLE 0: IDLE (Start Sig goes high)
Cycle 1: next_state is read and write
Cycle 2: State recognized. States: (writing to RAM2 and reading from RAM1) 
waddr1 = 255
waddr2 = 0
ram1writeenable = 0;
ram2writeenable = 1; (Active high)
raddr1 = 0;
raddr2 = 255
readMemSel = 0 (read to ram 1 enabled)
Cycle 3: 
raddr1 starts indexing
Cycle 5:
waddr2 starts indexing
Cycle 8: raddr1==6 next_state read2
Cycle 9: raddr1 stops: state = read2
Cycle 10: raddr2 = 0, raddr1 = 255
Cycle 11: waddr2 stops, state is write 1
Cycle 12: waddr2 = 255, waddr1 = 0

*/

int main(int argc, char** argv){
    VPPU *tb = new VPPU;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    setup(tb, tfp, argc, argv, "waveform_PPU.vcd");
    tb->startSigIN = 0;
    tb->clk = 0;
    int EEPROMEvOut = 0;
    int EEPROMOddOut = 1;

    int max_cycle = 600;
    for(int cycle = 0; (cycle < max_cycle) && !Verilated::gotFinish(); cycle++){
        if(cycle==1) tb->startSigIN = 1;
        if(cycle==2) tb->startSigIN = 0;
        
        tick(tb,tfp);
        if(cycle>=2 && cycle<= 5){ //behaviour, loads bits in bit reversed order
            int cycleZero = cycle-2;
            int cycleZeroRevInt = cycleZero+1;

            int revEv = (EEPROMEvOut&4)>>2 | (EEPROMEvOut&2) | (EEPROMEvOut&1)<<2;
            int revOdd = (EEPROMOddOut&4)>>2 | (EEPROMOddOut&2) | (EEPROMOddOut&1)<<2;
            
            check("writeEnable1", tb->weADDRen1, 1, cycle);
            check("changeVal", tb->change, 0, cycle);
            check("InputBridgeAddressRAM", tb->waddr1, cycleZero, cycle);
            check("InputBridgeAddressEEPROMEven", tb->EEPROMaddressEv, revEv, cycle);
            check("InputBridgeAddressEEPROMOdd", tb->EEPROMaddressOdd, revOdd, cycle);
            EEPROMEvOut = EEPROMEvOut+2;
            EEPROMOddOut = EEPROMOddOut+2;
            
        }
        if(cycle>=6 && cycle<= 7){//6 Sig goes high, 7 state is READ1, 8 is incrementing
            check("Done", tb->change, 1, cycle);
            check("readADDR2Buf", tb->weADDRen2, 0, cycle);
        }
        if(cycle>=8 && cycle <= 15){
            int expects = cycle-8;
            check("readADDR1Buf", tb->raddr1, expects, cycle);
        }
        if(cycle>=13&&cycle<=20){ //Pipelined twice
            int expects = cycle-13;
            check("write2Addr", tb->waddr2, expects, cycle);
            check("writeEnable2", tb->weADDRen2, 1, cycle);
        }
        if(cycle>=16 && cycle<=23){
            int expects = cycle-16;
            check("read2Addr", tb->raddr2, expects, cycle);
        }
    }
    //
    return finish(tb,tfp);
}
Synthesized on an ICE40UP5K using yosys and nextpnr. Pretty simple to make the project you can look [here](Makefile).
This build is for a 4 stage FFT but this can obviously be built up to N with a few tweaks. The 4 stage FFT is now working through all testbenchs and is working correctly. It operated at half the clock frequency HFOSC/2 being 24 MHz but I might try to adjust the critical path in mag2Bin to get the frequency up to 48 MHz. I am just waiting on the adc from digikey before I setup the display. To run the main testbench after looking at the file run make sim_top. After this run make yosys_synthesize and then finally run make next_pnrRep and make bitstream to pack top.bin. This will show you everything I have made to date. Synthesis and place and route outputs (top.json, top.asc, timing.json) are rebuilt by the Makefile and are not tracked, only the packed top.bin is.

Signal chain: the MCP3201 is read at 8 kSPS (24 MHz / 187 / 16), every 16 samples go through the FFT, and bins 1 to 8 (500 Hz to 4 kHz) are shown as one column each. Each LED in a column is double the magnitude of the one below it. Bars jump up straight away and fall one LED every decayFrames FFT frames (32 by default, about 64 ms per LED). Between columns everything is switched off for readDivCount/16 clocks so the 2N3904 column drivers can turn off fully and the previous column doesn't ghost.

Video:

https://github.com/user-attachments/assets/a05e287f-1762-4381-a237-b69075709cc5

Board Setup:

<img width="1932" height="1933" alt="d4bcff0e-2ac7-4c49-a855-90eca75db59b" src="https://github.com/user-attachments/assets/0ee0878f-e3e5-4d81-acd6-1174fde27027" />

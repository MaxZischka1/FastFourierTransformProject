Synthesized on an ICE40UP5K using yosys and nextpnr. Pretty simple to make the project you can look (here)[Makefile].
This build is for a 4 stage FFT but this can obviously be built up to N with a few tweaks. The 4-stage build runs at 44.23 MHz before I tried rewriting the SPI interface so those times are tbd. The # of logic cells is 1,533 and all 8 DSP blocks are used.

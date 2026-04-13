Early stages of a Radix-2 FFT IP block implemented on an ice40up5k. Will later be compared to a more parallel implementation on a MAX10 FPGA.

This is a double buffering implementation one of the simpliest only improving latency by 
improving time by not waiting for all Butterfly operations to be complete before saving to memory of O(Nlog(N)). Want to implement a single path delay feedback architechture later.
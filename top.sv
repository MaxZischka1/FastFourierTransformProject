module top #(parameter readDivCount = 8192)(
`ifdef VERILATOR
    input logic clk,
`endif
    input logic resetN,
    input logic startTrans,
    input logic adcData,
    output logic adcCs,
    output logic adcSclk,
    output logic [7:0] colOut,
    output logic [7:0] rowOut
);

`ifndef VERILATOR
logic clk;
SB_HFOSC #(.CLKHF_DIV("0b01")) osc(.CLKHFEN(1'b1), .CLKHFPU(1'b1), .CLKHF(clk));
`endif

logic [11:0] sample;
logic sampleValid;

adcSpi spi(.startTrans(startTrans), .dataIn(adcData), .resetN(resetN), .clk(clk),
    .scss(adcCs), .sclk(adcSclk), .validO(sampleValid), .dataOut(sample));

logic [11:0] fifoOut;
logic fifoValid;

fifo #(.width(12), .depth(16)) sampleFifo(.clock(clk), .clr(!resetN), .write(sampleValid),
    .dataIn(sample), .dataOut(fifoOut), .valid(fifoValid));

logic signed [15:0] fftOutRE, fftOutIM;
logic fftValid;

TopLevel fft(.dataInRE({1'b0, fifoOut[11:0], 3'd0}), .dataInIM(16'sd0), .clk(clk),
    .valid(fifoValid), .reset(resetN), .dataOutRE(fftOutRE), .dataOutIM(fftOutIM), .validOut(fftValid));

logic [7:0] mag;
logic magValid;

magToBin mag2bin(.FFTOutRE(fftOutRE), .FFTOutIM(fftOutIM), .validI(fftValid), .clk(clk),
    .reset(resetN), .MagOut(mag), .validO(magValid));

ledDriver #(.readDivCount(readDivCount)) leds(.clk(clk), .reset(resetN), .magIn(mag), .validI(magValid),
    .colOut(colOut), .rowOut(rowOut));

endmodule

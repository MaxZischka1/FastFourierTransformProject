module top #(parameter readDivCount = 16384, parameter decayFrames = 32)(
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

logic [1:0] resetSync, startSync;
initial resetSync = '0;
always_ff @(posedge clk) begin
    resetSync <= {resetSync[0], resetN};
    startSync <= {startSync[0], startTrans};
end

logic rstN;
assign rstN = resetSync[1];

logic [11:0] sample;
logic sampleValid;

adcSpi spi(.startTrans(startSync[1]), .dataIn(adcData), .resetN(rstN), .clk(clk),
    .scss(adcCs), .sclk(adcSclk), .validO(sampleValid), .dataOut(sample));

logic [11:0] fifoOut;
logic fifoValid;

fifo #(.width(12), .depth(16)) sampleFifo(.clock(clk), .clr(!rstN), .write(sampleValid),
    .dataIn(sample), .dataOut(fifoOut), .valid(fifoValid));

logic signed [15:0] fftOutRE, fftOutIM;
logic fftValid;

TopLevel fft(.dataInRE({~fifoOut[11], fifoOut[10:0], 4'd0}), .dataInIM(16'sd0), .clk(clk),
    .valid(fifoValid), .reset(rstN), .dataOutRE(fftOutRE), .dataOutIM(fftOutIM), .validOut(fftValid));

logic [7:0] mag;
logic magValid;

magToBin mag2bin(.FFTOutRE(fftOutRE), .FFTOutIM(fftOutIM), .validI(fftValid), .clk(clk),
    .reset(rstN), .MagOut(mag), .validO(magValid));

ledDriver #(.readDivCount(readDivCount), .decayFrames(decayFrames)) leds(.clk(clk), .reset(rstN), .magIn(mag), .validI(magValid),
    .colOut(colOut), .rowOut(rowOut));

endmodule

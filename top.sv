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

// logic [3:0] winIdx;
// always_ff @(posedge clk) begin
//     if(!rstN) winIdx <= '0;
//     else if(fifoValid) winIdx <= winIdx + 1'b1;
// end

// logic [3:0] winPos;
// assign winPos = winIdx[3] ? -winIdx : winIdx;

// logic [8:0] winCoeff;
// always_comb begin
//     case(winPos)
//         4'd1: winCoeff = 9'd10;
//         4'd2: winCoeff = 9'd37;
//         4'd3: winCoeff = 9'd79;
//         4'd4: winCoeff = 9'd128;
//         4'd5: winCoeff = 9'd177;
//         4'd6: winCoeff = 9'd219;
//         4'd7: winCoeff = 9'd246;
//         4'd8: winCoeff = 9'd256;
//         default: winCoeff = 9'd0;
//     endcase
// end

// logic [8:0] winCoeffReg;
// logic signed [15:0] centered;
// logic centeredValid;
// always_ff @(posedge clk) begin
//     winCoeffReg <= winCoeff;
//     centered <= {~fifoOut[11], fifoOut[10:0], 4'd0};
//     centeredValid <= fifoValid;
// end

// logic signed [25:0] windowProduct;
// assign windowProduct = centered * $signed({1'b0, winCoeffReg});

// logic signed [15:0] windowed;
// logic windowedValid;
// always_ff @(posedge clk) begin
//     windowed <= windowProduct[23:8];
//     windowedValid <= centeredValid;
// end

logic signed [15:0] fftOutRE, fftOutIM;
logic fftValid;

TopLevel fft(.dataInRE({{4{~fifoOut[11]}}, ~fifoOut[11], fifoOut[10:0]}), .dataInIM(16'sd0), .clk(clk),
    .valid(fifoValid), .reset(rstN), .dataOutRE(fftOutRE), .dataOutIM(fftOutIM), .validOut(fftValid));

logic [7:0] mag;
logic magValid;

magToBin mag2bin(.FFTOutRE(fftOutRE), .FFTOutIM(fftOutIM), .validI(fftValid), .clk(clk),
    .reset(rstN), .MagOut(mag), .validO(magValid));

ledDriver #(.readDivCount(readDivCount), .decayFrames(decayFrames)) leds(.clk(clk), .reset(rstN), .magIn(mag), .validI(magValid),
    .colOut(colOut), .rowOut(rowOut));

endmodule

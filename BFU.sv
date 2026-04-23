//Targetting the SB_MAC16 16x16 DSP. Need two in combination for
module BFU(
    input logic clk,
    input logic signed[15:0] dInREEv,
    input logic signed[15:0] dInREOdd,
    input logic signed[15:0] dInIMEv,
    input logic signed[15:0] dInIMOdd,
    input logic signed[15:0] wRE,
    input logic signed[15:0] wIM,
    output logic signed[31:0] dOutREEv,
    output logic signed[31:0] dOutREOdd,
    output logic signed[31:0] dOutIMEv,
    output logic signed[31:0] dOutIMOdd
);
    logic signed [31:0] dInREEvBuf, dInIMEvBuf;
    assign dInREEvBuf = 32'(dInREEv);
    assign dInIMEvBuf = 32'(dInIMEv);
    logic signed [31:0] oddCompRE, oddCompIM;

    assign oddCompRE = ((dInREOdd*wRE) - (dInIMOdd*wIM)) >>> 15;
    assign oddCompIM = ((dInREOdd*wIM) + (dInIMOdd*wRE)) >>> 15;
    
    always @(posedge clk) begin
        dOutREEv <= dInREEvBuf + oddCompRE;
        dOutREOdd <= dInREEvBuf - oddCompRE;
        dOutIMEv <= dInIMEvBuf + oddCompIM;
        dOutIMOdd <= dInIMEvBuf - oddCompIM;
    end
endmodule

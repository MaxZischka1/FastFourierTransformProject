//implement a continous adder first. Then move to to butterfly unit.
module BFU(
    input logic clk,
    input logic[15:0] dInREEv,
    input logic[15:0] dInREOdd,
    input logic [15:0] dInIMEv,
    input logic [15:0] dInIMOdd,
    input logic [15:0] wRE,
    input logic [15:0] wIM,
    output logic[15:0] dOutREEv,
    output logic[15:0] dOutREOdd,
    output logic[15:0] dOutIMEv,
    output logic[15:0] dOutIMOdd
);
logic [15:0] prevINRE1;
logic alternatingSig;

logic [31:0] oddFactorIM, oddFactorRE;
always_comb begin
    //would is omega was e^ipi need to change
    oddFactorRE = $signed(wRE)*$signed(dInREOdd) - $signed(wIM)*$signed(dInIMOdd);
    oddFactorIM = $signed(wIM)*$signed(dInREOdd) - $signed(wRE)*$signed(dInIMOdd);
end

always_ff @(posedge clk) begin
    dOutREEv <= $signed(dInREEv) + oddFactorRE[30:15];
    dOutREOdd <= $signed(dInREEv) - oddFactorRE[30:15];
    dOutIMEv <= $signed(dInIMEv) + oddFactorIM[30:15];
    dOutIMOdd <= $signed(dInIMEv) - oddFactorIM[30:15];
end


endmodule

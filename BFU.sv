//implement a continous adder first. Then move to to butterfly unit.
module BFU(
    input logic clk,
    input logic[15:0] dInRE,
    input logic [15:0] dInIM,
    output logic[15:0] dOutRE,
    output logic[15:0] dOutIM
);
logic [15:0] prevINRE1;
logic alternatingSig;
always_ff @(posedge clk) begin
    alternatingSig <= ~alternatingSig;
    prevINRE1 <= alternatingSig?dInRE:16'h0000;;
    dOutRE <= prevINRE1 + dInRE; 
    dOutIM <= dOutIM - dInIM;
end
endmodule

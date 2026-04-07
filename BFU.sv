//implement a continous adder first. Then move to to butterfly unit.
module BFU(
    input logic clk,
    input logic[15:0] dInRE,
    input logic [15:0] dInIM,
    output logic[15:0] dOutRE,
    output logic[15:0] dOutIM
);

always_ff @(posedge clk) begin
    dOutRE <= dOutRE + dInRE; 
    dOutIM <= dOutIM - dInIM;
end
endmodule

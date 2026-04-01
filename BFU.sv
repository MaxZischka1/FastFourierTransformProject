//implement a continous adder first. Then move to to butterfly unit.
module BFU(
    input logic clk,
    input logic[15:0] dIn,
    output logic[15:0] dOutRE,
    output logic[15:0] dOutIM
);

always_ff @(posedge clk) begin
    dOutRE <= dOutRE + dIn; 
    dOutIM <= dOutIM - dIn;
end
endmodule

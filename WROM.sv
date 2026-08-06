module WROM(
    input logic [1:0] twiddleAddress,
    output logic signed [15:0] omgRE,
    output logic signed [15:0] omgIM
);
always_comb begin
    case(twiddleAddress)
        2'h0: {omgIM,omgRE} = 32'h00007FFF;//RE 1
        2'h1: {omgIM,omgRE} = 32'h5A815A81;//RE and IM (1/root(2))
        2'h2: {omgIM,omgRE} = 32'h7FFF0000;//IM 1
        2'h3: {omgIM,omgRE} = 32'h5A815A81;//RE and IM (1/root(2))
        default: {omgIM,omgRE} = 32'h00000000;
    endcase
end
endmodule


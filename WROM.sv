module WROM(
    input logic [7:0] twiddleAddres,
    output logic [31:0] twiddleFactor
);
always_comb begin
    case(twiddleAddres)
        8'h1: twiddleFactor = 31'h00007FFF;//RE 1
        8'h2: twiddleFactor = 31'h5A815A81;//RE and IM (1/root(2))
        8'h3: twiddleFactor = 31'h7FFF0000;//IM 1
        8'h4: twiddleFactor = 31'h5A815A81;//RE and IM (1/root(2))
        default: twiddleFactor = 31'h00000000;
    endcase
end
endmodule
module testEEPROM(
    input logic [3:0] address, 
    output logic [15:0] sampleIn//start with
);

always_comb begin
    case(address)
        4'h0: sampleIn = 16'h0000;
        4'h1: sampleIn = 16'h5A82;
        4'h2: sampleIn = 16'h7FFF;
        4'h3: sampleIn = 16'h5A82;
        4'h4: sampleIn = 16'h0000;
        4'h5: sampleIn = 16'hA57E;
        4'h6: sampleIn = 16'h8000;
        4'h7: sampleIn = 16'hA57E;
    endcase
end


endmodule
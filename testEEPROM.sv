module testEEPROM(
    input logic [7:0] address, 
    output logic [15:0] sampleIn//start with
);

always_comb begin
    case(address)
        8'h0: sampleIn = 16'h0000;
        8'h1: sampleIn = 16'h5A82;
        8'h2: sampleIn = 16'h7FFF;
        8'h3: sampleIn = 16'h5A82;
        8'h4: sampleIn = 16'h0000;
        8'h5: sampleIn = 16'hA57E;
        8'h6: sampleIn = 16'h8000;
        8'h7: sampleIn = 16'hA57E;
        default: sampleIn = 16'h0000;
    endcase
end


endmodule

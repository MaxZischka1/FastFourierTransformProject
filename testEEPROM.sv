module testEEPROM(
    input logic [7:0] address, 
    output logic [15:0] sampleIn//start with
);

always_comb begin
    case(address)
        8'h0: sampleIn = 16'h0000;
        8'h1: sampleIn = 16'h0001;
        8'h2: sampleIn = 16'h0002;
        8'h3: sampleIn = 16'h0003;
        8'h4: sampleIn = 16'h0004;
        8'h5: sampleIn = 16'h0005;
        8'h6: sampleIn = 16'h0006;
        8'h7: sampleIn = 16'h0007;
        default: sampleIn = 16'h0000;
    endcase
end


endmodule

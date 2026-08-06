module testEEPROM(
    input logic [7:0] address, 
    output logic [15:0] sampleIn//start with
);

always_comb begin
    case(address)
        8'd0: sampleIn = 16'h0000;
        8'd1: sampleIn = 16'h0002;
        8'd2: sampleIn = 16'h0001;
        8'd3: sampleIn = 16'h0003;
        8'd4: sampleIn = 16'h0000;
        8'd5: sampleIn = 16'h0002;
        8'd6: sampleIn = 16'h0001;
        8'd7: sampleIn = 16'h0003;
        
        default: sampleIn = 16'h0000;
    endcase
end


endmodule

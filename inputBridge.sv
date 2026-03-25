module inputBridge(
    input logic startSig,
    input logic clk,
    output logic [7:0] address,
    output logic doneSig
);

logic trans;
logic [2:0] totCount;

always @(posedge clk) begin
    if(startSig && !trans) begin
        trans <= 1;
        doneSig <= 0;
    end
end
always @(posedge clk) begin
    if(trans) begin
        if(address != 7)
            address <= address + 1;
        else begin
            address <= 0;
            totCount <= totCount + 1;
        end
    end
    if(totCount == 1) begin
        trans <= 0;
        doneSig <= 1;
    end
end
endmodule

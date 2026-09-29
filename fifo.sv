module fifo #(
    parameter width = 8,
    parameter depth = 16   //must be a power of two
)(
    input logic clock,
    input logic clr,
    input logic write,
    input logic read,
    input logic [width-1:0] dataIn,
    output logic [width-1:0] dataOut,
    output logic full,
    output logic empty
);

localparam addr = $clog2(depth);

logic [width-1:0] mem [depth];
logic [addr:0] writePtr, readPtr; 

assign empty   = (writePtr == readPtr);
assign full    = (writePtr[addr-1:0] == readPtr[addr-1:0]) && (writePtr[addr] != readPtr[addr]);
assign dataOut = mem[readPtr[addr-1:0]]; //read is combinational, no latency

always_ff @(posedge clock) begin
    if(clr) begin
        writePtr <= 0;
        readPtr <= 0;
    end
    else begin
        if(write && !full) begin
            mem[writePtr[addr-1:0]] <= dataIn;
            writePtr <= writePtr + 1;
        end
        if(read && !empty) begin
            readPtr <= readPtr + 1;
        end
    end
end
endmodule

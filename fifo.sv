module fifo #(
    parameter width = 8,
    parameter depth = 16   //must be a power of two
)(
    input logic clock,
    input logic clr,
    input logic write,
    input logic [width-1:0] dataIn,
    output logic [width-1:0] dataOut,
    output logic valid
);

localparam addr = $clog2(depth);

logic [width-1:0] mem [depth];
logic [addr:0] writePtr, readPtr;

logic full;
assign full    = (writePtr[addr-1:0] == readPtr[addr-1:0]) && (writePtr[addr] != readPtr[addr]);
assign dataOut = mem[readPtr[addr-1:0]]; //read is combinational, no latency

logic bursting;
logic [addr:0] burstCount;
assign valid = bursting;

always_ff @(posedge clock) begin
    if(clr) begin
        bursting <= 1'b0;
        burstCount <= 0;
    end
    else if(bursting) begin
        burstCount <= burstCount - 1'b1;
        if(burstCount == 1) bursting <= 1'b0;
    end
    else if(full) begin
        bursting <= 1'b1;
        burstCount <= depth;
    end
end

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
        if(valid) begin
            readPtr <= readPtr + 1;
        end
    end
end
endmodule

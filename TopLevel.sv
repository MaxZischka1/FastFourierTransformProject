module TopLevel(
    input logic clk,
    input logic startSig,
    output logic [15:0] ram1Output,
    output logic [15:0] rdata1REO,
    output logic [15:0] rdata1IMO,
    output logic [15:0] rdata2REO,
    output logic [15:0] rdata2IMO,
    output logic [7:0] waddr1Out
);


logic doneSigIB;
// logic doneSigPP;


//latch from change
always @(posedge clk) begin
    if(doneSigIB) change <= 1;
end
logic change;
//BFU output reg
logic [15:0] BFUoutRE;
logic [15:0] BFUoutIM;
//read data port regs
logic [15:0] rdata1RE;
logic [15:0] rdata1IM;
logic [15:0] rdata2RE;
logic [15:0] rdata2IM;
//enables regs
logic weADDRen1;
logic weADDRen2;
//address regs
logic [7:0] addressOutIn;
logic [7:0] waddr1;
logic [7:0] waddr1PP;
logic [7:0] waddr2;
logic [7:0] raddr1;
logic [7:0] raddr2;
//output assignments
assign rdata1REO = rdata1RE;
assign rdata1IMO = rdata1IM;
assign rdata2REO = rdata2RE;
assign rdata2IMO = rdata2IM;
//MUXs for pingpong
logic [15:0] wdata1RE;
assign wdata1RE = (change?BFUoutRE:ram1Output);
assign waddr1 = change?waddr1PP:addressOutIn;

assign waddr1Out = waddr1;





inputBridge testInBridge(.clk(clk), .startSig(startSig), .address(addressOutIn), .doneSig(doneSigIB));
pingPongU PP1(.clk(clk), .startSig(doneSigIB), .waddr1(waddr1PP), .waddr2(waddr2), .raddr1(raddr1), .raddr2(raddr2), .weADDRen1(weADDRen1), .weADDRen2(weADDRen2));
testEEPROM EEPROM(.address(addressOutIn), .sampleIn(ram1Output)); //change .WDATA to be multiplexer for when pingpong
BRAM bram1RE(.wdata(wdata1RE), .waddr(waddr1), .we(weADDRen1), .clk(clk), .raddr(raddr1), .rdata(rdata1RE));
BRAM bram1IM(.wdata(BFUoutIM), .waddr(waddr1), .we(weADDRen1), .clk(clk), .raddr(raddr1), .rdata(rdata1IM));
BRAM bram2RE(.wdata(BFUoutRE), .waddr(waddr2), .we(weADDRen2), .clk(clk), .raddr(raddr2), .rdata(rdata2RE));
BRAM bram2IM(.wdata(BFUoutIM), .waddr(waddr2), .we(weADDRen2), .clk(clk), .raddr(raddr2), .rdata(rdata2IM));
BFU butUnit(.clk(clk), .dIn(rdata1RE), .dOutRE(BFUoutRE), .dOutIM(BFUoutIM));
endmodule

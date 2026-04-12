/*
Current issue to solve later. The clock cycles. There is a a singular edge delay between the read and write no matter what. 
So always the read should be 1 address less than the write.
Ontop of that there is a 1 clock delay from the BFU leading to a total of two cycle delay between an address read from
and its respective address written to. raddr-2 = waddr
*/

module TopLevel( //made the change where addresses now index from 0 to 7 instead of 0 to 6 before indexing to zero,
//as the waves show there is an 8th address but the weEnable swaps so it is 0 to 7.
    input logic clk,
    input logic startSig,
    output logic [15:0] ram1Output,
    output logic [15:0] rdata1REO,
    output logic [15:0] rdata1IMO,
    output logic [15:0] rdata2REO,
    output logic [15:0] rdata2IMO,
    output logic [7:0] waddr1Out,
    output logic [7:0] waddr2Out,
    output logic [15:0] BFUREout,
    output logic [15:0] BFUREinOut,
    output logic changeOut,
    output logic readMemSelOut,
    output logic [7:0] raddr1Out,
    output logic [7:0] raddr2Out,
    output logic weADDRen1Out,
    output logic weADDRen2Out
);


logic doneSigIB;
// logic doneSigPP;


//input bridge logic and regs

logic [7:0] addressOutIn;
logic transmitSigIB;

always @(posedge clk) begin
    if(doneSigIB) change <= 1;
end
logic change;
assign changeOut = change;
logic readMemSel;
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
logic weADDRen1PP;
logic [15:0] wdata1RE;
assign wdata1RE = (change?BFUoutRE:ram1Output);
assign waddr1 = change?waddr1PP:addressOutIn;
assign  weADDRen1 = (change?weADDRen1PP:transmitSigIB);
//output regs for write address
assign waddr1Out = waddr1;
assign waddr2Out = waddr2;
//BFU reg for MUX logic
logic [15:0] BFUREin;
logic [15:0] BFUIMin;
assign BFUREout = BFUoutRE;
assign BFUREinOut = BFUREin;
//readMemSel output
assign readMemSelOut = readMemSel;

assign raddr1Out = raddr1;
assign raddr2Out = raddr2;

assign weADDRen1Out = weADDRen1;
assign weADDRen2Out = weADDRen2;


inputBridge testInBridge(.clk(clk), .startSig(startSig), .address(addressOutIn), .transmitSig(transmitSigIB), .doneSig(doneSigIB));
pingPongU PP1(.clk(clk), .startSig(doneSigIB), .waddr1(waddr1PP), .waddr2(waddr2), .raddr1(raddr1), .raddr2(raddr2), 
.weADDRen1(weADDRen1PP), .weADDRen2(weADDRen2), .readMemSel(readMemSel));
testEEPROM EEPROM(.address(addressOutIn), .sampleIn(ram1Output)); //change .WDATA to be multiplexer for when pingpong
BRAM bram1RE(.wdata(wdata1RE), .waddr(waddr1), .we(weADDRen1), .clk(clk), .raddr(raddr1), .rdata(rdata1RE));
BRAM bram1IM(.wdata(BFUoutIM), .waddr(waddr1), .we(weADDRen1), .clk(clk), .raddr(raddr1), .rdata(rdata1IM));
BRAM bram2RE(.wdata(BFUoutRE), .waddr(waddr2), .we(weADDRen2), .clk(clk), .raddr(raddr2), .rdata(rdata2RE));
BRAM bram2IM(.wdata(BFUoutIM), .waddr(waddr2), .we(weADDRen2), .clk(clk), .raddr(raddr2), .rdata(rdata2IM));
//mux for .dIn of BFU 
assign BFUREin = readMemSel?rdata2RE:rdata1RE;
assign BFUIMin = readMemSel?rdata2IM:rdata1IM;
BFU butUnit(.clk(clk), .dInRE(BFUREin), .dInIM(BFUIMin), .dOutRE(BFUoutRE), .dOutIM(BFUoutIM));
endmodule

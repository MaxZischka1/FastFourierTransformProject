/*
Current issue to solve later. The clock cycles. There is a a singular edge delay between the read and write no matter what. 
So always the read should be 1 address less than the write.
Ontop of that there is a 1 clock delay from the BFU leading to a total of two cycle delay between an address read from
and its respective address written to. raddr-2 = waddr
*/
module TopLevel( //made the change where addresses now index from 0 to 7 instead of 0 to 6 before indexing to zero,
//as the waves show there is an 8th address but the weEnable swaps so it is 0 to 7.

//adding pause and giving computation time for what AGU does next. Address generation
    input logic clk,
    input logic startSig,
    output logic [7:0] ramOddAdd, ramEvAdd,
    output logic [15:0] omgREOut, omgIMOut,
    output logic [15:0] ram1OutputOddO, ram1OutputEvO,
    output logic [15:0] rdata1REOEv,rdata1REOOdd,rdata1IMOEv,rdata1IMOOdd,
    output logic [15:0] rdata2REOEv,rdata2REOOdd,rdata2IMOEv,rdata2IMOOdd,
    output logic [7:0] waddr1Out,waddr2Out,
    output logic [15:0] BFUREoutEvO, BFUIMoutEvO, BFUREoutOddO, BFUIMoutOddO,
    output logic readMemSelOut,
    output logic [7:0] raddr1Out, raddr2Out,
    output logic weADDRen1Out, weADDRen2Out
);

//EEPROM Outputs
assign ram1OutputOddO = ram1OutputOdd;
assign ram1OutputEvO = ram1OutputEv;

assign ramOddAdd = EEPROMaddressOdd;
assign ramEvAdd = EEPROMaddressEv;

//SBM16 OUTPUT REFERENCE
assign BFUREoutEvO = BFUoutEvRE;
assign BFUIMoutEvO = BFUoutEvIM;
assign BFUREoutOddO = BFUoutOddRE;
assign BFUIMoutOddO = BFUoutOddIM;
//input bridge logic and regs
logic change;
logic readMemSel;
//BFU output reg
logic signed [15:0] BFUoutEvRE, BFUoutEvIM, BFUoutOddRE,BFUoutOddIM;
//read data port regs
logic signed [15:0] rdataEv1RE,rdataEv1IM, rdataEv2RE, rdataEv2IM, rdataOdd1RE, rdataOdd1IM, rdataOdd2RE,rdataOdd2IM;
//enables regs
logic weADDRen1,weADDRen2;
//address regs
logic [7:0] waddr1,waddr2,raddr1,raddr2;
//output assignments
assign rdata1REOEv = rdataEv1RE;
assign rdata1REOOdd = rdataOdd1RE;
assign rdata1IMOEv = rdataEv1IM;
assign rdata1IMOOdd = rdataOdd1IM;
assign rdata2REOEv = rdataEv2RE;
assign rdata2REOOdd = rdataOdd2RE;
assign rdata2IMOEv = rdataEv2IM;
assign rdata2IMOOdd = rdataOdd2IM;
//MUXs for pingpong
logic signed [15:0] wdata1EvRE, wdata1OddRE;
logic signed [15:0] ram1OutputEv, ram1OutputOdd;
assign wdata1EvRE = (change?BFUoutEvRE:ram1OutputEv);
assign wdata1OddRE = (change?BFUoutOddRE:ram1OutputOdd);
//output regs for write address
assign waddr1Out = waddr1;
assign waddr2Out = waddr2;
//BFU reg for MUX logic
logic signed [15:0] BFUREinOdd, BFUREinEv, BFUIMinOdd, BFUIMinEv;

//readMemSel output
assign readMemSelOut = readMemSel;

assign raddr1Out = raddr1;
assign raddr2Out = raddr2;

assign weADDRen1Out = weADDRen1;
assign weADDRen2Out = weADDRen2;
//pipelining the outputs of 
logic [1:0] stageNum;

logic signed [15:0] omgRE,omgIM;

assign omgREOut = omgRE;
assign omgIMOut = omgIM;

logic [7:0] EEPROMaddressEv, EEPROMaddressOdd;



PPU PP1(.clk(clk), .startSigIN(startSig), .waddr1(waddr1), .waddr2(waddr2),
 .raddr1(raddr1), .raddr2(raddr2), 
.weADDRen1(weADDRen1), .weADDRen2(weADDRen2), .readMemSel(readMemSel), 
.change(change), .stageNum(stageNum),
.EEPROMaddressOdd(EEPROMaddressOdd), .EEPROMaddressEv(EEPROMaddressEv));


WROM twiddleFact(.twiddleAddress(stageNum), .omgRE(omgRE), .omgIM(omgIM));
testEEPROM EEPROMEv(.address(EEPROMaddressEv), .sampleIn(ram1OutputEv)); //change .WDATA to be multiplexer for when pingpong
testEEPROM EEPROMOdd(.address(EEPROMaddressOdd), .sampleIn(ram1OutputOdd)); //change .WDATA to be multiplexer for when pingpong

//Ram 1
BRAM bramEv1RE(.wdata(wdata1EvRE), .waddr(waddr1), .we(weADDRen1), .clk(clk), .raddr(raddr1), .rdata(rdataEv1RE));
BRAM bramEv1IM(.wdata(BFUoutEvIM), .waddr(waddr1), .we(weADDRen1), .clk(clk), .raddr(raddr1), .rdata(rdataEv1IM));
BRAM bramOdd1RE(.wdata(wdata1OddRE), .waddr(waddr1), .we(weADDRen1), .clk(clk), .raddr(raddr1), .rdata(rdataOdd1RE));
BRAM bramOdd1IM(.wdata(BFUoutOddIM), .waddr(waddr1), .we(weADDRen1), .clk(clk), .raddr(raddr1), .rdata(rdataOdd1IM));

//Ram2
BRAM bramEv2RE(.wdata(BFUoutEvRE), .waddr(waddr2), .we(weADDRen2), .clk(clk), .raddr(raddr2), .rdata(rdataEv2RE));
BRAM bramEv2IM(.wdata(BFUoutEvIM), .waddr(waddr2), .we(weADDRen2), .clk(clk), .raddr(raddr2), .rdata(rdataEv2IM));
BRAM bramOdd2RE(.wdata(BFUoutOddRE), .waddr(waddr2), .we(weADDRen2), .clk(clk), .raddr(raddr2), .rdata(rdataOdd2RE));
BRAM bramOdd2IM(.wdata(BFUoutOddIM), .waddr(waddr2), .we(weADDRen2), .clk(clk), .raddr(raddr2), .rdata(rdataOdd2IM));
//mux for .dIn of BFU 
assign BFUREinEv = readMemSel?rdataEv2RE:rdataEv1RE;
assign BFUIMinEv = readMemSel?rdataEv2IM:rdataEv1IM;
assign BFUREinOdd = readMemSel?rdataOdd2RE:rdataOdd1RE;
assign BFUIMinOdd = readMemSel?rdataOdd2IM:rdataOdd1IM;

//Reimplement for SBM16
SBM16 butUnit(.clk(clk), .d1InRE(BFUREinOdd), .d1InIM(BFUIMinOdd), 
.WInRE(omgRE), .WInIM(omgIM), .d2InRE(BFUREinEv), .d2InIM(BFUIMinEv), 
.dOutEvRE(BFUoutEvRE), .dOutEvIM(BFUoutEvIM),.dOutOddRE(BFUoutOddRE), .dOutOddIM(BFUoutOddIM));
endmodule


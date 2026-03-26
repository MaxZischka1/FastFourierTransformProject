module TopLevel(
    input logic clk,
    input logic startSig,
    output logic [15:0] ram1Output,
    output logic doneSigOut,
    output logic [7:0] bridgeaddyOut,
    output logic [15:0] rdataout,
    output logic [7:0] PPaddyOut
);

logic [7:0] addressOutIn;
logic doneSig;

logic [7:0] raddr;

logic [15:0] rdata;
// logic doneSigPP;
// logic enADDR;


assign bridgeaddyOut = addressOutIn;
assign doneSigOut = doneSig;
assign rdataout = rdata;
assign PPaddyOut = raddr;


inputBridge testInBridge(.clk(clk), .startSig(startSig), .address(addressOutIn), .doneSig(doneSig));
pingPongU PP1(.clk(clk), .startSig(doneSig), .addr(raddr));
testEEPROM EEPROM(.address(addressOutIn), .sampleIn(ram1Output)); //change .WDATA to be multiplexer for when pingpong
BRAM bram1(.wdata(ram1Output), .waddr(addressOutIn), .we(!doneSig), .clk(clk), .raddr(raddr), .rdata(rdata));

endmodule

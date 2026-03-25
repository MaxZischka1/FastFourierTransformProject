module TopLevel(
    input logic clk,
    input logic startSig,
    output logic [15:0] ram1Output,
    output logic doneSigOut,
    output logic [7:0] addyOut
);

logic [7:0] addressOutIn;
logic doneSig;

assign addyOut = addressOutIn;


assign doneSigOut = doneSig;

inputBridge testInBridge(.clk(clk), .startSig(startSig), .address(addressOutIn), .doneSig(doneSig));
testEEPROM EEPROM(.address(addressOutIn), .sampleIn(ram1Output)); //change .WDATA to be multiplexer for when pingpong
BRAM bram1(.WDATA(ram1Output), ;

endmodule

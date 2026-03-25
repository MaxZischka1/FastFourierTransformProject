`include "BRAM.sv"
module pingPongU #(parameter SAMPLE = 8)(
    input logic clk,
    input logic reset,
    input logic startSig,
    output logic [7:0] addr,
    output logic enADDR,
    output logic doneSIG
);
//dual RAM ReadWrite setup //4 RAMs require for IM and RE one is always reading(prev vales) the other is writing(cur vals)
//Initially use a UART transmission for signal DATA, hopefully move to ethernet.
//Hypothetically logic starts in EEPROM or SPRAM we have to import. Sent via Serial or Ethernet

//Don't use state machine approach try an active approach
logic [7:0] counter;
logic [1:0] RAMSig = 2;
logic doneTrans = 0;

always_ff @(posedge clk) begin //startSignal
    if(startSig == 1) begin
        RAMSig <= 2'd0;
        counter <= 7'd0;
    end
end

always_ff @(posedge clk) begin
    if(counter==7) begin
        if(RAMSig) 
            RAMSig = 0;
        else
            RAMSig = 1;
    end
end

always_ff @(posedge clk) begin
    if(RAMSig != 2'd2) 
        counter <= counter + 1;
end

assign addr = counter;
endmodule


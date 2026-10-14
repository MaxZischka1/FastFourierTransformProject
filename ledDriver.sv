//Computes magnitude of FFT and compresses output to 8 bits.
module ledDriver #(parameter readDivCount = 16384)(
    input logic clk,
    input logic reset,
    input logic [7:0] magIn,
    input logic validI, //output from BinMag
    output logic [7:0] colOut,
    output logic [7:0] rowOut
);

localparam int divCountWidth = $clog2(readDivCount);
logic [7:0] ppRam [32]; //This is ping pong RAM always 

logic [7:0] bufferOut;
logic toggleRW;


logic [3:0] writeCounter, readCounter, readCounterD;

logic [divCountWidth-1 : 0] divCounter;

always_ff @(posedge clk) begin
    if(!reset) begin
        divCounter <= '0;
        readCounter <= '0;
        readCounterD <= '0;
        writeCounter <= '0;
        toggleRW <= 1'b0;
    end
    else begin
        readCounterD <= readCounter;

        if(divCounter == divCountWidth'(readDivCount - 1)) begin
            divCounter <= '0;
            readCounter <= readCounter + 1'b1;
        end
        else divCounter <= divCounter + 1'b1;

        if(validI) begin
            writeCounter <= writeCounter + 1'b1;
            if(writeCounter == 4'd15) toggleRW <= ~toggleRW;
        end
    end
end

always_ff @(posedge clk) begin
    if(validI) ppRam[{toggleRW, writeCounter[0], writeCounter[1], writeCounter[2], writeCounter[3]}] <= magIn;
    bufferOut <= ppRam[{~toggleRW,readCounter}];
end

always_ff @(posedge clk) begin
    if(!reset) begin
        colOut <= 8'd0;
        rowOut <= 8'd0;
    end
    else if(readCounterD >= 4'd1 && readCounterD <= 4'd8) begin
        colOut <= 8'd1 << (readCounterD - 4'd1);
        casez(bufferOut)
            8'b1???????: rowOut <= 8'hFF;
            8'b01??????: rowOut <= 8'h7F;
            8'b001?????: rowOut <= 8'h3F;
            8'b0001????: rowOut <= 8'h1F;
            8'b00001???: rowOut <= 8'h0F;
            8'b000001??: rowOut <= 8'h07;
            8'b0000001?: rowOut <= 8'h03;
            default:     rowOut <= 8'h01;
        endcase
    end
    else begin
        colOut <= 8'd0;
        rowOut <= 8'd0;
    end
end

endmodule

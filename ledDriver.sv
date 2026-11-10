//Scans the 8 displayed FFT bins onto the 8x8 LED matrix as bar heights with fast attack and slow decay.
module ledDriver #(parameter readDivCount = 16384, parameter decayFrames = 32)(
    input logic clk,
    input logic reset,
    input logic [7:0] magIn,
    input logic validI, //output from BinMag
    output logic [7:0] colOut,
    output logic [7:0] rowOut
);

logic [3:0] writeCounter;
logic [$clog2(decayFrames+1)-1:0] frameCounter;
logic decayNow;
assign decayNow = frameCounter == $bits(frameCounter)'(decayFrames - 1);

logic [3:0] bin;
assign bin = {writeCounter[0], writeCounter[1], writeCounter[2], writeCounter[3]};

logic [3:0] level;
always_comb begin
    casez(magIn)
        8'b1???????: level = 4'd8;
        8'b01??????: level = 4'd7;
        8'b001?????: level = 4'd6;
        8'b0001????: level = 4'd5;
        8'b00001???: level = 4'd4;
        8'b000001??: level = 4'd3;
        8'b0000001?: level = 4'd2;
        8'b00000001: level = 4'd1;
        default:     level = 4'd0;
    endcase
end

logic [3:0] held [8];
logic [3:0] decayed;
assign decayed = held[3'(bin - 1'b1)] - 4'(decayNow && held[3'(bin - 1'b1)] != 4'd0);

always_ff @(posedge clk) begin
    if(!reset) begin
        writeCounter <= '0;
        frameCounter <= '0;
        for(int i = 0; i < 8; i++) held[i] <= '0;
    end
    else if(validI) begin
        writeCounter <= writeCounter + 1'b1;
        if(writeCounter == 4'd15) frameCounter <= decayNow ? '0 : frameCounter + 1'b1;
        if(bin != 4'd0 && bin <= 4'd8) held[3'(bin - 1'b1)] <= (level > decayed) ? level : decayed; //bin 0 is the DC offset and bins 9 to 15 mirror 7 to 1, neither is shown
    end
end

localparam int divCountWidth = $clog2(readDivCount);
logic [divCountWidth-1 : 0] divCounter;
logic [2:0] readCounter;

always_ff @(posedge clk) begin
    if(!reset) begin
        divCounter <= '0;
        readCounter <= '0;
        colOut <= 8'd0;
        rowOut <= 8'd0;
    end
    else begin
        if(divCounter == divCountWidth'(readDivCount - 1)) begin
            divCounter <= '0;
            readCounter <= readCounter + 1'b1;
        end
        else divCounter <= divCounter + 1'b1;

        if(divCounter < divCountWidth'(readDivCount/16 + 1)) begin
            colOut <= 8'd0;
            rowOut <= 8'd0;
        end
        else begin
            colOut <= 8'd1 << readCounter; //driving grounding outputs through 3904 selecting which column.
            rowOut <= 8'hFF >> (4'd8 - held[readCounter]);
        end
    end
end

endmodule

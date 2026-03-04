//https://www.farnell.com/datasheets/3215488.pdf
//might want to change to DPRAM

module BRAM (
    input logic [15:0] WDATA,
    input logic [15:0] MASK,
    input logic [7:0] WADDR,
    input logic WE,
    input logic CLK,
    input logic [7:0] RADDR,
    input logic RE,
    output logic [15:0] RDATA
);

logic [15:0] internal [255:0];

always_ff @(posedge CLK) begin
    if(WE) begin
        for(int i = 0; i < 16; i++) begin
            if(!MASK[i]) internal[WADDR][i] <= WDATA[i]; //256 by 16bit RAM Cells(256x65365)
        end
    end
    RDATA <= internal[RADDR];
end

endmodule
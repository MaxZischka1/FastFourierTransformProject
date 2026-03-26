//https://www.farnell.com/datasheets/3215488.pdf
//might want to change to DPRAM

module BRAM (
    input logic [15:0] wdata,
    input logic [7:0] waddr,
    input logic we,
    input logic clk,
    input logic [7:0] raddr,
    output logic [15:0] rdata
);

logic [15:0] internal [255:0];

always_ff @(posedge clk) begin
    if(we) begin
        for(int i = 0; i < 16; i++) begin
            internal[waddr][i] <= wdata[i]; //256 by 16bit RAM Cells(256x65365)
        end
    end
    rdata <= internal[raddr];
end

endmodule

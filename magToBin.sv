//implement an alpha beta min max
module magToBin(
input logic [15:0] FFTOutRE,
input logic [15:0] FFTOutIM,
input logic validI,
input logic clk,
input logic reset,
output logic [7:0] MagOut,
output logic validO
);

logic [15:0] FFTOutREAbs,FFTOutIMAbs;
logic [15:0] FFTOutMAX,FFTOutMIN;
logic [15:0] MagOut17;
logic [2:0] validPipe;


always_ff @(posedge clk) begin
    FFTOutREAbs <= FFTOutRE[15]?((~FFTOutRE)+1):FFTOutRE;
    FFTOutIMAbs <= FFTOutIM[15]?((~FFTOutIM)+1):FFTOutIM;

    {FFTOutMAX,FFTOutMIN} <= (FFTOutREAbs > FFTOutIMAbs)?{FFTOutREAbs,FFTOutIMAbs} : {FFTOutIMAbs,FFTOutREAbs};

    MagOut17 <= FFTOutMAX + (FFTOutMIN>>1);
end

always_ff @(posedge clk) begin
    if(!reset) validPipe <= '0;
    else validPipe <= {validPipe[1:0], validI};

end

assign MagOut = MagOut17[15:8];

assign validO = validPipe[2];


endmodule
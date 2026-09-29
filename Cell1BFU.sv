module Cell1BFU(
    input logic clk,
    input logic valid,
    input logic reset,
    input logic en,
    input logic signed [15:0] interOddRE1,
    input logic  signed [15:0] interOddIM1,
    output logic validO,
    output logic  signed [15:0] dOutOddIM,
    output logic  signed [15:0] dOutOddRE
);

logic EvOdd;

always_ff @(posedge clk) begin
    if(!reset) begin
        EvOdd <= 1'b0;
        dOutOddRE <= 16'b0;
        dOutOddIM <= 16'b0;
        validO <= 1'b0;
    end
    else begin
    if(en) begin
    validO <= valid;
    if(valid) begin 
        EvOdd <= EvOdd ^ 1'b1;
        if(EvOdd==1'b1) begin
            dOutOddRE <= interOddIM1;
            dOutOddIM <= -interOddRE1;
        end
        else begin
            dOutOddRE <= interOddRE1;
            dOutOddIM <= interOddIM1;
        end
        end
    end
    end

end





endmodule
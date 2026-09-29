module DelayLine #(parameter depth=4, size=4)
(
    input logic valid,
    input logic clk,
    input logic en,
    input logic reset,
    input logic [size-1:0] dataIn,
    output logic validOut,
    output logic [size-1:0] dataOut
);

    logic [size-1:0] stage [depth];
    logic [depth-1:0] pipeReg;

    always_ff @(posedge clk) begin
        if (!reset) begin
            pipeReg <= '0;
            for (int i = 0; i < depth; i++)
                stage[i] <= '0;
        end else if (en) begin
            stage[0]   <= dataIn;
            pipeReg[0] <= valid;
            for (int i = 1; i < depth; i++) begin
                stage[i]   <= stage[i-1];
                pipeReg[i] <= pipeReg[i-1];
            end
        end
    end

    assign validOut = pipeReg[depth-1];
    assign dataOut  = stage[depth-1];

endmodule
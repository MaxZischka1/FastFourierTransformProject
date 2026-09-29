module MUX2 #(parameter size=16)(
    input logic sel,
    input logic [size-1:0] m1,
    input logic [size-1:0] m2,
    output logic [size-1:0] muxOut
);
    assign muxOut = sel?m2:m1;
endmodule

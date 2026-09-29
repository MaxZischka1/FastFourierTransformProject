//Chain SDF Cells
module TopLevel(
    input logic signed [15:0] dataInRE,
    input logic signed [15:0] dataInIM,
    input logic clk,
    input logic valid,
    input logic reset,
    output logic signed [15:0] dataOutRE,
    output logic signed [15:0] dataOutIM,
    output logic validOut
);
    logic signed [15:0] dataInREInt[3], dataInIMInt [3];
    logic validInt[10];

     SDFCell#(.size(16))sdfCell4(.dataInRE(dataInRE), .dataInIM(dataInIM), .clk(clk), .valid(valid), .reset(reset), 
    .dataOutRE(dataInREInt[0]), .dataOutIM(dataInIMInt[0]), .validOut(validInt[0]));

    SDFCell#(.size(8))sdfCell3(.dataInRE(dataInREInt[0]), .dataInIM(dataInIMInt[0]), .clk(clk), .valid(validInt[0]), .reset(reset), 
    .dataOutRE(dataInREInt[1]), .dataOutIM(dataInIMInt[1]), .validOut(validInt[1]));
    // genvar i;
    // generate for(i = 1; i < 10; i++) begin : sdfStages
    //     SDFCell#(.size(1024 >> i)) u_sdf(.dataInRE(dataInREInt[i-1]), .dataInIM(dataInIMInt[i-1]), .clk(clk), .valid(validInt[i-1]), .reset(reset), 
    // .dataOutRE(dataInREInt[i]), .dataOutIM(dataInIMInt[i]), .validOut(validInt[i]));
    // end
    // endgenerate

    SDFCell#(.size(4))sdfCell2(.dataInRE(dataInREInt[1]), .dataInIM(dataInIMInt[1]), .clk(clk), .valid(validInt[1]), .reset(reset), 
    .dataOutRE(dataInREInt[2]), .dataOutIM(dataInIMInt[2]), .validOut(validInt[2]));

    SDFCell0#(.size(2)) sdfCell1(.dataInRE(dataInREInt[2]), .dataInIM(dataInIMInt[2]), .clk(clk), .valid(validInt[2]), .reset(reset), 
    .dataOutRE(dataOutRE), .dataOutIM(dataOutIM), .validOut(validOut));
    

endmodule
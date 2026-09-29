/*RULE 1. All system that have valid Out passed from valid Real*/
module SDFCell0 #(parameter size = 2)(
    input logic signed [15:0] dataInRE,
    input logic signed [15:0] dataInIM,
    input logic clk,
    input logic valid,
    input logic reset,
    output logic signed [15:0] dataOutRE,
    output logic signed [15:0] dataOutIM,
    output logic validOut
);
   
    logic [15:0] dataSubOutRE, dataSubOutIM; //Subtraction outputs
    logic [15:0] mux1OutRE, mux1OutIM; //outputs from input MUX
    logic [15:0] SROutRE, SROutIM;
    logic mux1Sel;
    logic validSR;
    logic [15:0] dataAddOutRE, dataAddOutIM;
    logic adderValidOut;
    logic muxValidSel;


    logic EvOdd;
    always_ff @(posedge clk) begin
        if(!reset) EvOdd <= 0;
        else if(valid) EvOdd <= EvOdd ^ 1;
    end

    assign mux1Sel = EvOdd;

    //MUXs say what the inputs to the FIFO should be
    MUX2 #(.size(16))mux1RE(.sel(mux1Sel), .m1(dataInRE), .m2(dataSubOutRE), .muxOut(mux1OutRE)); 
    MUX2 #(.size(16))mux1IM(.sel(mux1Sel), .m1(dataInIM), .m2(dataSubOutIM), .muxOut(mux1OutIM));
    
    DelayLine #(.depth(size/2), .size(16))mainShiftRE(.dataIn(mux1OutRE), .valid(valid), .dataOut(SROutRE), .reset(reset), .validOut(validSR), .clk(clk), .en(1'b1));
    DelayLine #(.depth(size/2), .size(16))mainShiftIM(.dataIn(mux1OutIM), .valid(valid), .dataOut(SROutIM), .reset(reset), .validOut(), .clk(clk), .en(1'b1));
    
    DelayLine #(.depth((size/2)), .size(1))delOverHalf(.dataIn(EvOdd), .valid(valid), .dataOut(muxValidSel), .reset(reset), .validOut(), .clk(clk), .en(1'b1));

    //step 1 of 2 in the SDF is adding the even components
    dataAdder dataAddRE(.data1In(SROutRE), .data2In(dataInRE), .dataOutEv(dataAddOutRE), .dataOutOdd(dataSubOutRE));

    dataAdder dataAddIM(.data1In(SROutIM), .data2In(dataInIM), .dataOutEv(dataAddOutIM), .dataOutOdd(dataSubOutIM));
    
    //Step 2 in the SDF 
    
    

    MUX2 #(.size(16))muxOutRE(.sel(muxValidSel), .m1(dataAddOutRE), .m2(SROutRE), .muxOut(dataOutRE)); //MUXs decide if you should skip adder or not
    MUX2 #(.size(16))muxOutIM(.sel(muxValidSel), .m1(dataAddOutIM), .m2(SROutIM), .muxOut(dataOutIM));
    MUX2 #(.size(1))muxOutValid(.sel(muxValidSel), .m1(validSR), .m2(validSR), .muxOut(validOut));

    

endmodule


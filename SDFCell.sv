/*
This SDFCell is at the final stage making N=2 so all exponential values are 1 meaning it would
not make sense to dedicate an entire BFU to those operations.
*/

module SDFCell#(parameter size = 8)(
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
    logic mux1Sel, mux2Sel;
    logic validSR;
    logic [15:0] dataAddOutRE, dataAddOutIM;
    logic [15:0] BFUOutRE, BFUOutIM;
    logic fHalfValid, sHalfValid;
    logic adderValidOut, BFUValidOut;
    logic muxValidSel;
    logic [15:0] dataAddOutREp2, dataAddOutIMp2;

    

    localparam int logSize = $clog2(size);
    logic [logSize-1:0] counter;
    logic overHalf;
    logic [logSize-1:0] sizeReg = logSize'(size - 1);
    logic [logSize-1:0] second = logSize'(size / 2);


    always_ff @(posedge clk) begin //This should be implemented in top level
        if(!reset) counter <= '0;
        else begin
        if(valid) begin
            if(counter == sizeReg) counter <= '0;
            else counter <= counter + 1'b1;
        end
        end
    end


    always_comb begin
        
        overHalf = (counter >= second);
    end


    assign mux1Sel = overHalf;
    //MUXs say what the inputs to the FIFO should be
    MUX2 #(.size(16))mux1RE(.sel(mux1Sel), .m1(dataInRE), .m2(dataSubOutRE), .muxOut(mux1OutRE)); 
    MUX2 #(.size(16))mux1IM(.sel(mux1Sel), .m1(dataInIM), .m2(dataSubOutIM), .muxOut(mux1OutIM));
    
    

    DelayLine #(.depth(size/2), .size(16))mainShiftRE(.dataIn(mux1OutRE), .valid(valid), .dataOut(SROutRE), .reset(reset), .validOut(validSR), .clk(clk), .en(1'b1));
    DelayLine #(.depth(size/2), .size(16))mainShiftIM(.dataIn(mux1OutIM), .valid(valid), .dataOut(SROutIM), .reset(reset), .validOut(), .clk(clk), .en(1'b1));
    
    DelayLine #(.depth((size/2)), .size(1))del4OverHalf(.dataIn(overHalf), .valid(valid), .dataOut(muxValidSel), .reset(reset), .validOut(), .clk(clk), .en(1'b1));
   



    

    //step 1 of 2 in the SDF is adding the even components
    dataAdder dataAddRE(.data1In(SROutRE), .data2In(dataInRE), .dataOutEv(dataAddOutRE), .dataOutOdd(dataSubOutRE));

    dataAdder dataAddIM(.data1In(SROutIM), .data2In(dataInIM), .dataOutEv(dataAddOutIM), .dataOutOdd(dataSubOutIM));
    
    //Step 2 in the SDF 
    
    assign fHalfValid = muxValidSel?1'b0:validSR;
    assign sHalfValid = muxValidSel?validSR:1'b0;
   
    if (size == 4) begin : gen_CellN
        DelayLine #(.depth(1), .size(1))validToOut(.dataIn(muxValidSel), .valid(valid), .dataOut(mux2Sel), .reset(reset), .validOut(), .clk(clk), .en(1'b1));
        DelayLine #(.depth(1), .size(16))del2REOut(.dataIn(dataAddOutRE), .valid(fHalfValid), .dataOut(dataAddOutREp2), .reset(reset), .validOut(adderValidOut), .clk(clk), .en(1'b1));
        DelayLine #(.depth(1), .size(16))del2IMOut(.dataIn(dataAddOutIM), .valid(fHalfValid), .dataOut(dataAddOutIMp2), .reset(reset), .validOut(), .clk(clk), .en(1'b1));
        Cell1BFU BFU(.clk(clk), .reset(reset), .valid(sHalfValid), .interOddRE1(SROutRE), .interOddIM1(SROutIM),
        .dOutOddIM(BFUOutIM), .dOutOddRE(BFUOutRE), .validO(BFUValidOut), .en(1'b1));
    end
    
    else begin : gen_Cell1
        DelayLine #(.depth(2), .size(1))validToOut(.dataIn(muxValidSel), .valid(valid), .dataOut(mux2Sel), .reset(reset), .validOut(), .clk(clk), .en(1'b1));
        DelayLine #(.depth(2), .size(16))del2REOut(.dataIn(dataAddOutRE), .valid(fHalfValid), .dataOut(dataAddOutREp2), .reset(reset), .validOut(adderValidOut), .clk(clk), .en(1'b1));
        DelayLine #(.depth(2), .size(16))del2IMOut(.dataIn(dataAddOutIM), .valid(fHalfValid), .dataOut(dataAddOutIMp2), .reset(reset), .validOut(), .clk(clk), .en(1'b1));
        SBM16 #(.logN(4),.logSize(logSize)) BFU(.clk(clk), .reset(reset), .valid(sHalfValid), .interOddRE1(SROutRE), .interOddIM1(SROutIM),
        .dOutOddIM(BFUOutIM), .dOutOddRE(BFUOutRE), .validO(BFUValidOut), .en(1'b1));
    end
    
    MUX2 #(.size(16))muxOutRE(.sel(mux2Sel), .m1(dataAddOutREp2), .m2(BFUOutRE), .muxOut(dataOutRE)); //MUXs decide if you should skip adder or not
    MUX2 #(.size(16))muxOutIM(.sel(mux2Sel), .m1(dataAddOutIMp2), .m2(BFUOutIM), .muxOut(dataOutIM));
    MUX2 #(.size(1))muxOutValid(.sel(mux2Sel), .m1(adderValidOut), .m2(BFUValidOut), .muxOut(validOut));

endmodule
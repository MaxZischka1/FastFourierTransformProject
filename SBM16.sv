//Implement DIT SBM16 calculation
//(d1InRE+d1InIM-d2InRE-d2InIM)*(wInRE-wInIM)
//(d1InRE*wInRE(RE)  +  d1InIM*wInRE(IM)  -  d2InRE*wInRE(RE)   -   d2InIM*wInRE(IM)   -   d1InRE*wInIM(IM)   +    d1InIM*wInIM(RE)    +   d2InRE*wInIM(IM)   - d2InIM*wInIM(RE))

//This is combinational to my understanding We need a register delay of 3 clock cycles
module SBM16(
    input logic clk,
    input logic signed [15:0] d1InRE,
    input logic signed [15:0] d1InIM,
    input logic signed [15:0] WInRE,
    input logic signed [15:0] WInIM,
    input logic signed [15:0] d2InRE,
    input logic signed [15:0] d2InIM,
    output logic signed [31:0] dOutEvIM,
    output logic signed [31:0] dOutEvRE,
    output logic signed [31:0] dOutOddIM,
    output logic signed [31:0] dOutOddRE
    


);
`ifdef VERILATOR
/* verilator lint_off UNUSEDSIGNAL */
logic signed [16:0] interRE1, interIM1;
logic signed [31:0] interOdd2MRE, interOdd2MIM;
logic signed [16:0] sumEvRE, sumEvIM, sumOddRE, sumOddIM;
/* verilator lint_on UNUSEDSIGNAL */

assign sumEvRE = d1InRE + d2InRE;
assign sumEvIM = d1InIM + d2InIM;

assign interRE1 = (d1InRE - d2InRE);
assign interIM1 = (d1InIM - d2InIM);


assign interOdd2MRE = interRE1*WInRE - interIM1*WInIM;
assign interOdd2MIM = interRE1*WInIM + interIM1*WInRE;


    

    always_ff @(posedge clk) begin
        dOutEvRE <= {{16{sumEvRE[16]}},sumEvRE[16:1]}; 
        dOutEvIM <= {{16{sumEvIM[16]}},sumEvIM[16:1]};
        dOutOddRE <= {{16{interOdd2MRE[31]}},interOdd2MRE[31:16]};
        dOutOddIM <= {{16{interOdd2MIM[31]}},interOdd2MIM[31:16]};
    end
    
     
`else//TO DO : Implement a SBMAC16 use 4 DSPs 2 for multiplication and two accumulation. (I can't think of a more effecient approach)
    logic signed [16:0] interRE1, interIM1;
    logic signed [31:0] dspOddRE, interOddIM, dspInterRE;
    logic signed [16:0] sumEvRE, sumEvIM, sumOddRE, sumOddIM;

    assign interRE1 = (d1InRE - d2InRE);
    assign interIM1 = (d1InIM - d2InIM);

    assign sumEvRE = (d1InRE + d2InRE);
    assign sumEvIM = (d1InIM + d2InIM);

    
    
//DSP Block #1: 16x16 Multiplication and nothing else.
//---- OUTPUT from 1 and 2 is REAL 3 and 4 is IMAG -----
    SB_MAC16 #(
                .TOPOUTPUT_SELECT(2'b01), // registered outputs
                .TOPADDSUB_LOWERINPUT(2'b10), // multiplier hi bits
                .TOPADDSUB_UPPERINPUT(1'b1), // input C
                .TOPADDSUB_CARRYSELECT(2'b11), // top carry in is bottom carry out
                .BOTOUTPUT_SELECT(2'b01), // registered outputs
                .BOTADDSUB_LOWERINPUT(2'b10), // multiplier lo bits
                .BOTADDSUB_UPPERINPUT(1'b1), // input D
                .BOTADDSUB_CARRYSELECT(2'b00), // bottom carry in constant 0
                .A_SIGNED(1'b1),
                .B_SIGNED(1'b1)
    ) mult16x16_noAddRE(
                .CLK(clk),
                .A(interRE1),
                .B(WInRE),
                .C(16'd0),
                .D(16'd0),
                .O(dspInterRE)
                
        );
//DSP Block #2 does a 16x16 mult and then accumlates with the output of the first output
    SB_MAC16 #(
                .TOPOUTPUT_SELECT(2'b10), // registered outputs
                .TOPADDSUB_LOWERINPUT(2'b10), // multiplier hi bits
                .TOPADDSUB_UPPERINPUT(1'b1), // input C
                .TOPADDSUB_CARRYSELECT(2'b11), // top carry in is bottom carry out
                .BOTOUTPUT_SELECT(2'b01), // registered outputs
                .BOTADDSUB_LOWERINPUT(2'b10), // multiplier lo bits
                .BOTADDSUB_UPPERINPUT(1'b1),// input D
                .A_SIGNED(1'b1),
                .B_SIGNED(1'b1) 
    ) mult16x16_subRE(
                .CLK(clk),
                .A(d1InRE),
                .B(WInRE),
                .C(dspInterRE[31:16]),
                .D(dspInterRE[15:0]),
                .O(dspOddRE[31:0]),
                .ADDSUBBOT(1'b1),//subtract
                .ADDSUBTOP(1'b1)
        );
//DSP Block #3 and #4 repeats blocks for complement
SB_MAC16 #(
                .TOPOUTPUT_SELECT(2'b01), // registered outputs
                .TOPADDSUB_LOWERINPUT(2'b10), // multiplier hi bits
                .TOPADDSUB_UPPERINPUT(1'b1), // input C
                .TOPADDSUB_CARRYSELECT(2'b11), // top carry in is bottom carry out
                .BOTOUTPUT_SELECT(2'b01), // registered outputs
                .BOTADDSUB_LOWERINPUT(2'b10), // multiplier lo bits
                .BOTADDSUB_UPPERINPUT(1'b1), // input D
                .BOTADDSUB_CARRYSELECT(2'b00), // bottom carry in constant 0
                .A_SIGNED(1'b1),
                .B_SIGNED(1'b1)
    ) mult16x16_noAddIM(
                .CLK(clk),
                .A(d1InRE),
                .B(WInIM),
                .C(16'd0),
                .D(16'd0),
                .O(dspOddIM)
        );
//DSP Block #2 does a 16x16 mult and then accumlates with the output of the first output
    SB_MAC16 #(
                .TOPOUTPUT_SELECT(2'b10), // registered outputs
                .TOPADDSUB_LOWERINPUT(2'b10), // multiplier hi bits
                .TOPADDSUB_UPPERINPUT(1'b1), // input C
                .TOPADDSUB_CARRYSELECT(2'b11), // top carry in is bottom carry out
                .BOTOUTPUT_SELECT(2'b01), // registered outputs
                .BOTADDSUB_LOWERINPUT(2'b10), // multiplier lo bits
                .BOTADDSUB_UPPERINPUT(1'b1),// input D
                .A_SIGNED(1'b1),
                .B_SIGNED(1'b1) 
    ) mult16x16_addIM(
                .CLK(clk),
                .A(d1InIM),
                .B(WInRE),
                .C(dspInterIM[31:16]),
                .D(dspInterIM[15:0]),
                .O(dspOutIM[31:0])        
                );
        
        
        assign dOutOddRE = dspOddRE[31:16];
        assign dOutOddIM = dspOddIM[31:16];

        always @(posedge clk) begin
            dOutEvRE = sumEvRE[16:1];
            dOutEvIM = sumEvIM[16:1];
        end

//Feed outputs into a 16 bit adder made from LUTs. Try to implement two BFUs in architechture.
`endif



endmodule

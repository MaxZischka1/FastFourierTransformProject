module SBM16(
    input logic clk,
    input logic signed [15:0] d1InRE,
    input logic signed [15:0] d1InIM,
    input logic signed [15:0] WInRE,
    input logic signed [15:0] WInIM,
    input logic signed [15:0] d2InRE,
    input logic signed [15:0] d2InIM,
    output logic signed [31:0] dataOutIM,
    output logic signed [31:0] dataOutRE
    


);
`ifdef VERILATOR
/* verilator lint_off UNUSEDSIGNAL */
logic signed [31:0] interMedRE, interMedIM;
logic signed [16:0] sumRE, sumIM;
/* verilator lint_on UNUSEDSIGNAL */

assign interMedRE = (d1InRE*WInRE - d1InIM*WInIM);
assign interMedIM = (d1InRE*WInIM + d1InIM*WInRE);

assign sumRE = ($signed(interMedRE[31:15]) + $signed({d2InRE[15],d2InRE}));
assign sumIM = ($signed(interMedIM[31:15]) +  $signed({d2InIM[15],d2InIM}));

    

    always_ff @(posedge clk) begin
        dataOutRE <= {{16{sumRE[16]}},sumRE[16:1]}; 
        dataOutIM <= {{16{sumIM[16]}},sumIM[16:1]};
       
    end
    
     
`else//TO DO : Implement a SBMAC16 use 4 DSPs 2 for multiplication and two accumulation. (I can't think of a more effecient approach)
    logic signed[31:0] dspInterRE, dspInterRENeg, dspInterIM;
    logic signed[31:0] dspOutRE, dspOutIM;
    logic signed [16:0] sumRE, sumIM;
    
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
                .A(d1InIM),
                .B(WInIM),
                .C(16'd0),
                .D(16'd0),
                .O(dspInterRE)
                
        );
//DSP Block #2 does a 16x16 mult and then accumlates with the output of the first output
    assign dspInterRENeg = (~dspInterRE)+1;//apply complement
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
                .C(dspInter1[31:16]),
                .D(dspInter1[15:0]),
                .O(dspOutRE[31:0]),
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
                .O(dspInterIM)
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

        assign sumIM = (dspOutIM[32:16] + {d2InIM[15],d2InIM});
        assign sumRE = (dspOutRE[32:16] + {d2InRE[15],d2InRE});
        assign dataOutRE = sumRE[16:1];
        assign dataOutIM = sumIM[16:1];

//Feed outputs into a 16 bit adder made from LUTs. Try to implement two BFUs in architechture.
`endif



endmodule

module SBM16(
    input logic clk,
    input logic signed [15:0] d1InRE,
    input logic signed [15:0] d1InIM,
    input logic signed [15:0] WInRE,
    input logic signed [15:0] WInIM,
    input logic signed [15:0] d2InRE,
    input logic signed [15:0] d2InIM,
    output logic signed [15:0] dataOutRE,
    output logic signed [15:0] dataOutIM
);
`ifdef VERILATOR
/* verilator lint_off UNUSEDSIGNAL */
logic signed [31:0] interMedRE, interMedIM;
/* verilator lint_on UNUSEDSIGNAL */

assign interMedRE = (d1InRE*WInRE - d1InIM*WInIM);
assign interMedIM = (d1InRE * WInIM + d1InIM * WInRE);
    always_ff @(posedge clk) begin
        dataOutRE <= $signed(interMedRE[30:15]) + $signed(d2InRE);
        dataOutIM <= $signed(interMedIM[30:15]) + $signed(d2InIM);
    end
    
     
`else//TO DO : Implement a SBMAC16 use 4 DSPs 2 for multiplication and two accumulation. (I can't think of a more effecient approach)
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
    ) mult16x16_addRE(
                .CLK(clk),
                .A(d1In),
                .B(WInRE),
                .C(d2In[31:16]),
                .D(d2In[15:0]),
                .O(dataOuRE[31:0]),
                .CO(dataOutRE[32])
        );
    SB_MAC16 #(
                .TOPOUTPUT_SELECT(2'b01), // registered outputs
                .TOPADDSUB_LOWERINPUT(2'b10), // multiplier hi bits
                .TOPADDSUB_UPPERINPUT(1'b1), // input C
                .TOPADDSUB_CARRYSELECT(2'b11), // top carry in is bottom carry out
                .BOTOUTPUT_SELECT(2'b01), // registered outputs
                .BOTADDSUB_LOWERINPUT(2'b10), // multiplier lo bits
                .BOTADDSUB_UPPERINPUT(1'b1), // input D
                .BOTADDSUB_CARRYSELECT(2'b00) // bottom carry in constant 0
    ) mult16x16_addIM(
                .CLK(clk),
                .A(d1In),
                .B(WInIM),
                .C(d2In[31:16]),
                .D(d2In[15:0]),
                .O(dataOutIM[31:0]),
                .CO(dataOutIM[32])
        );

`endif



endmodule

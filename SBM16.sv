//(d1InRE+d1InIM-d2InRE-d2InIM)*(wInRE-wInIM)
//Register the inputs
//**IMPORTANT**Before synthesizing analyize clock cycles on DSP Blocks
module SBM16 #(parameter int logN = 3, logSize = 3)(
    input logic clk,
    input logic valid,
    input logic en,
    input logic reset,
    input logic signed [15:0] interOddRE1,
    input logic  signed [15:0] interOddIM1,
    output logic validO,
    output logic  signed [15:0] dOutOddIM,
    output logic  signed [15:0] dOutOddRE
);
`ifdef VERILATOR
/* verilator lint_off UNUSEDSIGNAL */
logic signed [31:0] interOdd2MRE, interOdd2MIM, interOdd3MRE, interOdd3MIM;
logic signed [15:0] interOddIM1p, WInREp, WInIMp, WInRE, WInIM;
localparam int stride = 1 << (logN - logSize);
logic [logN-2:0] counter;
logic [1:0] validOpipe;

logic [15:0] twiddleRE [1 << (logN-1)]; 
logic [15:0] twiddleIM [1 << (logN-1)];

initial begin
    $readmemh("twiddleRE.hex", twiddleRE);
    $readmemh("twiddleIM.hex", twiddleIM);
end

/* verilator lint_on UNUSEDSIGNAL */

    assign WInRE = twiddleRE[counter];
    assign WInIM = twiddleIM[counter];

    always_ff @(posedge clk) begin
        if(!reset) begin
            interOdd3MRE <= 32'd0;
            interOdd3MIM <= 32'd0;

            interOdd2MRE <= 32'd0;
            interOdd2MIM <= 32'd0;
            validOpipe <= 2'd0;

            counter <= '0;
        end else begin
        
        if(en) begin
        
        validOpipe <= {validOpipe[0], valid};
        //pipeline Regs for inputs
        interOddIM1p <= interOddIM1;
        WInIMp <= WInIM;
        WInREp <= WInRE;
        //

        interOdd2MRE <= interOddRE1*WInRE;
        interOdd2MIM <= interOddRE1*WInIM;

        interOdd3MRE <= interOdd2MRE - interOddIM1p*WInIMp;
        interOdd3MIM <= interOdd2MIM + interOddIM1p*WInREp;

        if(valid) counter <= counter + (logN-1)'(stride); //always just wraps

    
        end

        end
    end
        assign dOutOddRE = interOdd3MRE[30:15];
        assign dOutOddIM = interOdd3MIM[30:15];
        assign validO = validOpipe[1];
    
`else//TO DO : Check datasheet
    logic signed [31:0] interOdd2MRE, interOdd2MIM, interOdd3MRE, interOdd3MIM;
    logic signed [15:0] interOddIM1p, WInREp, WInIMp, WInRE, WInIM;
    localparam int stride = 1 << (logN - logSize);
    logic [logN-2:0] counter;
    logic [1:0] validOpipe;

    logic [15:0] twiddleRE [1 << (logN-1)]; 
    logic [15:0] twiddleIM [1 << (logN-1)];

    initial begin
        $readmemh("twiddleRE.hex", twiddleRE);
        $readmemh("twiddleIM.hex", twiddleIM);
    end
    assign WInRE = twiddleRE[counter];
    assign WInIM = twiddleIM[counter];
    
//DSP Block #1: 16x16 Multiplication and nothing else.

//---- OUTPUT from 1 and 2 is REAL 3 and 4 is IMAG -----
    SB_MAC16 #(
                .TOPOUTPUT_SELECT(2'b00), // registered outputs CHECK THIS CHANGEEDDEDE
                .TOPADDSUB_LOWERINPUT(2'b10), // multiplier hi bits
                .TOPADDSUB_UPPERINPUT(1'b1), // input C
                .TOPADDSUB_CARRYSELECT(2'b11), // top carry in is bottom carry out
                .BOTOUTPUT_SELECT(2'b00), // registered outputs  CHECK THIS CHANGEEDDEDE
                .BOTADDSUB_LOWERINPUT(2'b10), // multiplier lo bits
                .BOTADDSUB_UPPERINPUT(1'b1), // input D
                .BOTADDSUB_CARRYSELECT(2'b00), // bottom carry in constant 0
                .A_SIGNED(1'b1),
                .B_SIGNED(1'b1)
    ) mult16x16_noAddRE(
        
                .CLK(clk),
                .CE(en),
                .A(interOddRE1),
                .B(WInRE),
                .C(16'd0),
                .D(16'd0),
                .O(interOdd2MRE)
                
        );
//DSP Block #2 does a 16x16 mult and then accumlates with the output of the first output
    SB_MAC16 #(
                .TOPOUTPUT_SELECT(2'b01), // registered outputs
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
                .CE(en),
                .A(interOddIM1),
                .B(WInIM),
                .C(interOdd2MRE[31:16]),
                .D(interOdd2MRE[15:0]),
                .O(interOdd3MRE[31:0]),
                .ADDSUBBOT(1'b1),//subtract
                .ADDSUBTOP(1'b1)
        );
//DSP Block #3 and #4 repeats blocks for complement
SB_MAC16 #(
                .TOPOUTPUT_SELECT(2'b00), // registered outputs SAME AS ABOVE CHECK
                .TOPADDSUB_LOWERINPUT(2'b10), // multiplier hi bits
                .TOPADDSUB_UPPERINPUT(1'b1), // input C
                .TOPADDSUB_CARRYSELECT(2'b11), // top carry in is bottom carry out
                .BOTOUTPUT_SELECT(2'b00), // registered outputs
                .BOTADDSUB_LOWERINPUT(2'b10), // multiplier lo bits
                .BOTADDSUB_UPPERINPUT(1'b1), // input D
                .BOTADDSUB_CARRYSELECT(2'b00), // bottom carry in constant 0
                .A_SIGNED(1'b1),
                .B_SIGNED(1'b1)
    ) mult16x16_noAddIM(
                .CLK(clk),
                .CE(en),
                .A(interOddRE1),
                .B(WInIM),
                .C(16'd0),
                .D(16'd0),
                .O(interOdd2MIM)
        );
//DSP Block #2 does a 16x16 mult and then accumlates with the output of the first output
    SB_MAC16 #(
                .TOPOUTPUT_SELECT(2'b01), // registered outputs
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
                .CE(en),
                .A(interOddIM1),
                .B(WInRE),
                .C(interOdd2MIM[31:16]),
                .D(interOdd2MIM[15:0]),
                .O(interOdd3MIM[31:0])        
                );
    always_ff @(posedge clk) begin
        if(!reset) begin
            counter <= '0;
            validOpipe <= '0;
            interOddIM1p <= 16'd0;
            WInREp <= 16'd0;
            WInIMp <= 16'd0;
        end else begin
        if(en) begin
            if(valid) counter <= counter + (logN-1)'(stride); 
            validOpipe <= {validOpipe[0], valid};
            interOddIM1p <= interOddIM1;

            WInIMp <= WInIM;
            WInREp <= WInRE;
        end
    end
    end
        
        
        assign dOutOddRE = interOdd3MRE[30:15];
        assign dOutOddIM = interOdd3MIM[30:15];
        assign validO = validOpipe[1];

//Feed outputs into a 16 bit adder made from LUTs. Try to implement two BFUs in architechture.
`endif
endmodule


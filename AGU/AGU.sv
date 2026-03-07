
`include "BRAM/BRAM.sv"
module AGU #(parameter SAMPLE = 8)(
    input logic clk,
    input logic reset,
    input startSig,
    output logic [7:0] re1ADDR,
    output logic [7:0] im1ADDR,
    output logic [7:0] re2ADDR,
    output logic [7:0] im2ADDR
    output logic re1ADDREN,
    output logic im1ADDREN,
    output logic re2ADDREN,
    output logic im2ADDREN,
    output logic doneSIG
)
//dual RAM ReadWrite setup //4 RAMs require for IM and RE one is always reading(prev vales) the other is writing(cur vals)
//Initially use a UART transmission for signal DATA, hopefully move to ethernet.
//Hypothetically logic starts in EEPROM or SPRAM we have to import. Sent via Serial or Ethernet

logic [SAMPLE-1 : 0] counter;

typedef enum logic[1:0] { //pingpong with states 2 and 3
    START,
    1Write2Read,
    1Read2Write,
    DONE
} states;
states state, next_state;


always_comb begin : stateShifts
    next_state = state;
    case(state)
        START:begin
            if(startSig) next_state = 1Write2Read;
        end

        1Write2Read:begin

        end

    endcase



end

always_ff @(posedge clk) begin : AddressGenerationBlock
    if(reset) begin
        counter <= 0;
        next_state <= START;
    end
    else state <= next_state;

end

endmodule


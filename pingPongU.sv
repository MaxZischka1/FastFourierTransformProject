module pingPongU #(parameter SAMPLE = 8)(
    input logic clk,
    input logic startSig,
    output logic [7:0] addr
    // output logic enADDR,
    // output logic doneSIG
);
//dual RAM ReadWrite setup //4 RAMs require for IM and RE one is always reading(prev vales) the other is writing(cur vals)
//Initially use a UART transmission for signal DATA, hopefully move to ethernet.
//Hypothetically logic starts in EEPROM or SPRAM we have to import. Sent via Serial or Ethernet
typedef enum logic [1:0] {
    IDLE,
    RAM1S,
    // RAM2S,
    DONE
} states;

states state, next_state;

logic [SAMPLE-1:0] counter;


always_comb begin
    case(state) 
        IDLE: begin
            next_state = states'(startSig? RAM1S: IDLE);
        end
        RAM1S: next_state = states'((counter==7)? DONE:RAM1S);
        DONE: next_state = IDLE;
        default: next_state = IDLE;
    endcase
end

always_ff @(posedge clk) begin //startSignal
    state <= next_state;
    if(state==RAM1S) begin
        counter <= counter +1;
    end
    else counter <= 0;
end

assign addr = counter;
endmodule


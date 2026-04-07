module inputBridge(
    input logic startSig,
    input logic clk,
    output logic [7:0] address,
    output logic transmitSig,
    output logic doneSig
);
typedef enum logic [1:0] {  
    IDLE,
    TRANSMITTING,
    DONE
} states;
states state, next_state;
logic [2:0] totCount;

assign transmitSig = (state==TRANSMITTING)?1:0;

always_ff @(posedge clk) begin
    state <= next_state;
end
always_comb begin
    case(state)
        IDLE: begin
            next_state = states'((startSig)?TRANSMITTING:IDLE);
            doneSig = 0;
        end
        TRANSMITTING: begin
            next_state = states'((totCount==1)?DONE:TRANSMITTING);
        end
        DONE: begin
            next_state = IDLE;
            doneSig = 1;
        end
        default: next_state = IDLE;
    endcase
end

always @(posedge clk) begin
    
    if(state==TRANSMITTING)
        if(address != 7)
            address <= address + 1;
        else begin
            address <= 0;
            totCount <= totCount + 1;
        end
    end
endmodule

module uart_rx(
    input logic rx,
    input logic clock,
    input logic clr,
    output logic [7:0] data,
    output logic [15:0] realCounter
);


typedef enum  logic[1:0]{  
    Idle,
    Start,
    Transmitting,
    Finish
} states;



states state, next_state;

logic [7:0] counter;

always_comb begin : stateMachine
    next_state = state;
    case(state)
        Idle:begin
            if(rx==0)
                next_state = Start;
        end
        Start:begin
            if(realCounter==232)
                next_state = Transmitting;
        end
        Transmitting:begin
            // if(realCounter==434) begin
            if(counter == 8) next_state = Finish;
        end
        Finish:begin
            next_state = Idle;
        end
    endcase
end

always_ff @(posedge clock or posedge clr) begin
    realCounter <= realCounter + 1;
    if(clr) begin
        state <= Idle;
        realCounter <= 0;
        counter <= 0;
        data <= 0;
    end
    else
        state <= next_state;

    if (state == Finish) counter <= 0;

    if((state == Idle) && rx == 0) begin
        realCounter <= 0;
        data <= 0;
    end

    if((state == Start) && realCounter == 232) begin
         realCounter <= 0;
    end

    if((state==Transmitting) && (realCounter==434)) begin
        realCounter <= 0;
        counter <= counter + 1;
        data <= {rx,data[7:1]};
    end
end








endmodule
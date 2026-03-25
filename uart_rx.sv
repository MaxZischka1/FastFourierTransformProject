module uart_rx(
    input logic rx,
    input logic clock,
    input logic clr,
    output logic [7:0] data,
    output logic [15:0] realCounter,
    output logic done
);

typedef enum  logic[2:0]{  //state machine
    Idle,
    Start,
    Transmitting,
    CheckStop,
    Finish
} states;
states state, next_state;
logic [7:0] counter;
reg rx_sync, rx_syncW;

always_comb begin : stateMachine //change state logic
    next_state = state;
    case(state)
        Idle:begin
            if(rx_sync==0) begin
                next_state = Start;
            end
        end
        Start:begin
            if(realCounter==232)
                next_state = Transmitting;
        end
        Transmitting:begin
            // if(realCounter==434) begin
            if((counter == 8)) next_state = CheckStop; //suffecient hold time
        end
        CheckStop:begin
            if(rx_syncW && realCounter == 232) next_state = Finish;
        end

        Finish:begin
            next_state = Idle;
        end
    endcase
end

always_ff @(posedge clock or posedge clr) begin //sutff todo in states
    if(clr) begin
        state <= Idle;
        realCounter <= 0;
        counter <= 0;
        data <= 0;
    end
    else state <= next_state;
        
    case(state) 
        Idle: begin
            if((rx_sync==0)&&(!clr)) begin
                realCounter <= 0;
                data <= 0;
                done <= 0;
            end
        end
        Start: begin
            if ((realCounter == 232) && !clr)
                realCounter <= 0;
            else realCounter <= realCounter + 1;
        end
        Transmitting: begin
            if((realCounter==434) && !clr) begin
                realCounter <= 0;
                counter <= counter + 1;
                data <= {rx_syncW,data[7:1]};
            end else realCounter <= realCounter + 1;
        end
        CheckStop: begin
            realCounter <= realCounter + 1;
        end
        Finish: begin
            done <= 1;
            counter <= 0;
        end
    endcase
end

always_ff @(posedge clock or posedge clr) begin //synchronize data through two clocked FFs
    if(clr) begin
        rx_sync <= 1;
        rx_syncW <= 1;
    end
    else begin
        rx_syncW <= rx;
        rx_sync <= rx_syncW;
    end
end
endmodule
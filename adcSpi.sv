//Targetting SPI interface for MCP3201
// 3 pin SPI sclk(slave clock), DOUT and CS two outputs one input
module adcSpi(
    input logic startTrans,
    input logic dataIn,
    input logic resetN,
    input logic clk,
    output logic scss,
    output logic sclk,
    output logic validO,
    output logic [11:0] dataOut
);

typedef enum logic [2:0] { 
    Idle,
    Start,
    Wait,
    Null,
    Shift,
    Finish
} states;
states state, next_state;
logic [3:0] fullCounter;
logic [5:0] internalCounter;
logic changeCount; //indicates change of count

localparam internalCount = 48; //38000000/800000

always_ff @(posedge clk) begin
    if(!resetN) begin
        dataOut <= 12'd0;
        fullCounter <= 0;
        internalCounter <= 0;
        state <= Idle;
        validO <= 0;
        sclk <= 0;
        scss <= 1'd1;
    end
    else begin
        state <= next_state;
            if(internalCounter == internalCount - 1) begin
                    sclk <= ~sclk;
                    internalCounter <= 0;
                    changeCount <= 1'd0;
                    fullCounter <= fullCounter + 1;
            end 
            else begin
            changeCount <= 1'd0;
            internalCounter <= internalCounter + 1;
            if(internalCounter == internalCount/2 -1) begin
                 sclk <= ~sclk;
                 changeCount <= 1'd1;
            end
            end 

        case(state)
        Idle: begin
            fullCounter <= 0;
            validO <= 0;
            sclk <= 0;
            scss <= 1'd1;
        end
        Start: begin
            scss <= 1'd0;
            validO <= 1'd0;
        end
        Wait: begin
            scss <= 1'd0;
            validO <= 1'd0;
        end
        Null: begin
            scss <= 1'd0;
            validO <= 1'd0;
        end
        Shift: begin
            if(changeCount) dataOut <= {dataOut[10:0], dataIn};
            validO <= 1'd0;
        end
        Finish: begin
            validO <= 1'd1;
            scss <= 1'd1;
        end
        endcase
    end
end

always_comb begin
    case(state)
        Idle: begin
            if(startTrans == 1'd1 && changeCount) next_state = Start;
            else next_state = Idle;
        end
        Start: begin
            if(fullCounter==1 && changeCount) next_state = Wait;
            else next_state = Start;
        end
        Wait: begin
            if(fullCounter == 3 && changeCount) next_state = Null;
            else next_state = Wait;
        end
        Null: begin
            if(fullCounter==4) begin
                if(dataIn == 0) next_state = Shift;
                else next_state = Idle;
            end
        end
        Shift: begin
            if(changeCount && fullCounter == 15) next_state = Finish;
            else next_state = Shift;
        end
        Finish: begin
            next_state = Idle;
        end




        default: next_state = Idle;
    endcase
end



endmodule
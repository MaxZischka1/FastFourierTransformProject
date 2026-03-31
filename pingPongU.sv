module pingPongU #(parameter SAMPLE = 8)(
    input logic clk,
    input logic startSig,
    output logic [7:0] waddr1,
    output logic [7:0] waddr2,
    output logic [7:0] raddr1,
    output logic [7:0] raddr2,
    output logic weADDRen1,
    output logic weADDRen2 //only need one with a not gate

);
//dual RAM ReadWrite setup //4 RAMs require for IM and RE one is always reading(prev vales) the other is writing(cur vals)
//Initially use a UART transmission for signal DATA, hopefully move to ethernet.
//Hypothetically logic starts in EEPROM or SPRAM we have to import. Sent via Serial or Ethernet
typedef enum logic [1:0] {
    IDLE,
    READ1WRITE2,//M1R(loading set of data from mem1)MAM2W(writing to next set of data to data 2)
    WRITE1READ2,//same idea just swapped
    DONE
} states;

states state, next_state;

logic transCompRW, transCompWR;
logic fftComp;
logic [SAMPLE-1:0] counter;


always_comb begin //state trans block
    case(state)
        IDLE: begin
            next_state = states'((startSig)?READ1WRITE2:IDLE);
            //set addresses to 0
            waddr1 = 8'd0;
            waddr2 = 8'd0;
            raddr1 = 8'd0;
            raddr2 = 8'd0;
            //all enables 0
            weADDRen1 = 1'd0;
            weADDRen2 = 1'd0;
        end
        READ1WRITE2: begin
            next_state = states'((transCompRW)?WRITE1READ2:READ1WRITE2);
        end
        WRITE1READ2: begin
            next_state = states'((transCompWR)?((fftComp)?DONE:READ1WRITE2):WRITE1READ2);
        end
        DONE: begin
            next_state = IDLE;
        end
        default: next_state = IDLE;
    endcase
end


always_ff @(posedge clk) begin //startSignal
    state <= next_state;
end

endmodule


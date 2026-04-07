//dual RAM ReadWrite setup //4 RAMs require for IM and RE one is always reading(prev vales) the other is writing(cur vals)
//Initially use a UART transmission for signal DATA, hopefully move to ethernet.
//Hypothetically logic starts in EEPROM or SPRAM we have to import. Sent via Serial or Ethernet
module pingPongU #(parameter SAMPLE = 8)( //integrate sample more as time goes
    input logic clk,
    input logic startSig,
    output logic [7:0] waddr1,
    output logic [7:0] waddr2,
    output logic [7:0] raddr1,
    output logic [7:0] raddr2,
    output logic weADDRen1,
    output logic weADDRen2, //only need one with a not gate
    output logic readMemSel //0 for mem1, 1 for mem2
);
typedef enum logic [1:0] {
    IDLE,
    READ1WRITE2,//M1R(loading set of data from mem1)MAM2W(writing to next set of data to data 2)
    WRITE1READ2,//same idea just swapped
    DONE
} states;

states state, next_state;

logic transCompR1W2, transCompW1R2; //switch statements for when counters reach specific number
logic fftComp; //doneSig buffer basically
logic [7:0] waddr1Buf, waddr2Buf, raddr1Buf, raddr2Buf; //buffers for the outputs just to manipulate
logic [SAMPLE-1:0] iteratStep; //this is checking what iteration of FFT we are on.
//combinational transition logic
assign transCompR1W2 = (raddr1Buf==7);
assign transCompW1R2 = (waddr1Buf==7);
//output buffers
assign raddr1 = raddr1Buf;
assign raddr2 = raddr2Buf;
assign waddr1 = waddr1Buf;
assign waddr2 = waddr2Buf;
//readmemSel
logic readMemSelBuf;
assign readMemSel = readMemSelBuf; //start in read2

always_comb begin //state trans block
    case(state)
        IDLE: begin
            next_state = states'((startSig)?READ1WRITE2:IDLE);
            //all enables 0
            fftComp = 1'd0;
            weADDRen1 = 1'd0;
            weADDRen2 = 1'd0;
            readMemSelBuf = 1'd1;
        end
        READ1WRITE2: begin
            next_state = states'((transCompR1W2)?WRITE1READ2:READ1WRITE2);
            //ram1en
            weADDRen1 = 1'd0;
            //ram2en
            weADDRen2 = 1'd1;
            fftComp = 1'd0;

            readMemSelBuf = 1'd0; //read from 1
        end
        //possibly include an intermediate state to zero out buffers
        WRITE1READ2: begin
            next_state = states'((transCompW1R2)?((fftComp)?DONE:READ1WRITE2):WRITE1READ2);
            weADDRen1 = 1'd1;//ram1en
            weADDRen2 = 1'd0;//ram2en
            fftComp = 1'd0;
            readMemSelBuf = 1'd1; //read from 2
        end
        DONE: begin
            next_state = IDLE;
            weADDRen1 = 1'd0;//ram1en
            weADDRen2 = 1'd0;//ram2en
            fftComp = 1'd1;
            readMemSelBuf = 1'd1;
        end
        default: next_state = IDLE;
    endcase
end
always_ff @(posedge clk) begin //startSignal
    state <= next_state;
    case(state)
        IDLE: begin
            waddr1Buf <= 8'd0;
            waddr2Buf <= 8'd0;
            raddr1Buf <= 8'd0;
            raddr2Buf <= 8'd0;            
        end
        READ1WRITE2: begin
            //ram1 counter(read)
            waddr1Buf <= 8'd0;
            raddr1Buf <= raddr1Buf + 1;
            //ram2Config
            raddr2Buf <= 8'd0;
            waddr2Buf <= waddr2Buf + 1;
        end
        WRITE1READ2:begin
            //ram1Config
            waddr1Buf <= waddr1Buf + 1;
            raddr1Buf <= 8'd0;
            //ram2Config
            raddr2Buf <= raddr2Buf + 1;
            waddr2Buf <= 8'd0;
        end
        default: begin
            waddr1Buf <= 8'd0;
            waddr2Buf <= 8'd0;
            raddr1Buf <= 8'd0;
            raddr2Buf <= 8'd0; 
        end
    endcase
    if(transCompR1W2||transCompW1R2) begin
        iteratStep <= iteratStep + 1;
    end
end



endmodule


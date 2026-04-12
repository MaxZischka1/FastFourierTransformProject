//dual RAM ReadWrite setup //4 RAMs require for IM and RE one is always reading(prev vales) the other is writing(cur vals)
//Initially use a UART transmission for signal DATA, hopefully move to ethernet.
//Hypothetically logic starts in EEPROM or SPRAM we have to import. Sent via Serial or Ethernet
module pingPongU #(parameter SAMPLE = 8)( //current issue solving is getting address transition correct,
//should go from 0 to 7 with other RAM staying at a consistant 0. May need an IF statement. Then start BFU construction
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
typedef enum logic [2:0] {
    IDLEW,
    TRANS,
    WRITE2,//M1R(loading set of data from mem1)MAM2W(writing to next set of data to data 2)
    WRITE1,//same idea just swapped
    DONEW
} states_write;
states_write statew, next_statew;

typedef enum logic [1:0] {
    IDLER,
    READ1,//M1R(loading set of data from mem1)MAM2W(writing to next set of data to data 2)
    READ2,//same idea just swapped
    DONER
} states_read;
states_read stater, next_stater;

logic writeComp, readComp; //switch statements for when counters reach specific number
logic [7:0] waddr1Buf, waddr2Buf, raddr1Buf, raddr2Buf; //buffers for the outputs just to manipulate
logic [SAMPLE-1:0] iteratStep; //this is checking what iteration of FFT we are on.
//combinational transition logic
assign readComp = (raddr1Buf==7||raddr2Buf==7);
assign writeComp = (waddr1Buf==7||waddr2Buf==7);
//output buffers
assign raddr1 = raddr1Buf;
assign raddr2 = raddr2Buf;
assign waddr1 = waddr1Buf;
assign waddr2 = waddr2Buf;
//readmemSel
logic readMemSelBuf;
assign readMemSel = readMemSelBuf; //start in read2

logic holdFlag;


always_comb begin //state trans block
    case(statew)
        IDLEW: begin
            next_statew = states_write'((startSig)?TRANS:IDLEW);
            //all enables 0
            weADDRen1 = 1'd0;
            weADDRen2 = 1'd0;
        end
        TRANS: begin
            next_statew = states_write'((holdFlag)?WRITE2:TRANS);
            weADDRen1 = 1'd0;
            weADDRen2 = 1'd0;
        end
        WRITE2: begin
            next_statew = states_write'((writeComp)?WRITE1:WRITE2);
            //ram1en
            weADDRen1 = 1'd0;
            //ram2en
            weADDRen2 = 1'd1;
        end
        //possibly include an intermediate state to zero out buffers
        WRITE1: begin
            next_statew = states_write'((writeComp)?((iteratStep==7)?DONEW:WRITE2):WRITE1);
            weADDRen1 = 1'd1;//ram1en
            weADDRen2 = 1'd0;//ram2en
        end
        DONEW: begin
            next_statew = IDLEW;
            weADDRen1 = 1'd0;//ram1en
            weADDRen2 = 1'd0;//ram2en
        end
        default: begin
            next_statew = IDLEW;
            weADDRen1 = 1'd0;//ram1en
            weADDRen2 = 1'd0;//ram2en
        end
    endcase

    case(stater)
        IDLER: begin
            next_stater = states_read'((startSig)?READ1:IDLER);
            readMemSelBuf = 1'd1;
        end
        READ1: begin
            next_stater = states_read'((readComp)?READ2:READ1);
            readMemSelBuf = 1'd0; //read from 1
        end
        //possibly include an intermediate state to zero out buffers
        READ2: begin
            next_stater = states_read'((readComp)?((iteratStep==7)?DONER:READ1):READ2);
            readMemSelBuf = 1'd1; //read from 2
        end
        DONER:begin
            next_stater = IDLER;
            readMemSelBuf = 1'd1;
        end
        default: begin
            next_stater = IDLER;
            readMemSelBuf = 1'd1;
        end
    endcase
end
always_ff @(posedge clk) begin //startSignal
    statew <= next_statew;
    stater <= next_stater;
    case(statew)
        IDLEW: begin
            waddr1Buf <= 8'd0;
            waddr2Buf <= 8'd0; 
            holdFlag <= 1'd0;           
        end
        TRANS: begin
            waddr1Buf <= 8'd0;
            waddr2Buf <= 8'd0; 
            holdFlag <= 1'd1;           
        end
        WRITE2: begin
            //ram1 counter(read)
            waddr1Buf <= 8'd0;
            waddr2Buf <= waddr2Buf + 1;
            holdFlag <= 1'd0;
        end
        WRITE1:begin
            //ram1Config
            waddr1Buf <= waddr1Buf + 1;
            waddr2Buf <= 8'd0;
            holdFlag <= 1'd0;
        end
        default: begin
            waddr1Buf <= 8'd0;
            waddr2Buf <= 8'd0;
            holdFlag <= 1'd0;
        end
    endcase

    case(stater)
        IDLER: begin
            raddr1Buf <= 8'd0;
            raddr2Buf <= 8'd0; 
                       
        end
        READ1: begin
            //ram1 counter(read)
            raddr1Buf <= raddr1Buf + 1;
            //ram2Config
            raddr2Buf <= 8'd0;
        end
        READ2:begin
            //ram1Config
            raddr1Buf <= 8'd0;
            //ram2Config
            raddr2Buf <= raddr2Buf + 1;

        end
        default: begin
            raddr1Buf <= 8'd0;
            raddr2Buf <= 8'd0;            
        end
    endcase
    if(readComp) begin
        iteratStep <= iteratStep + 1;
    end
end



endmodule


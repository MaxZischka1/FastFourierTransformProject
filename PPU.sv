//dual RAM ReadWrite setup //4 RAMs require for IM and RE one is always reading(prev vales) the other is writing(cur vals)
//Initially use a UART transmission for signal DATA, hopefully move to ethernet.
//Hypothetically logic starts in EEPROM or SPRAM we have to import. Sent via Serial or Ethernet
module PPU ( //current issue solving is getting address transition correct,
//should go from 0 to 7 with other RAM staying at a consistant 0. May need an IF statement. Then start BFU construction
    input logic startSigIN,
    input logic clk,
    output logic [7:0] waddr1,
    output logic [7:0] waddr2,
    output logic [7:0] raddr1,
    output logic [7:0] raddr2,
    output logic weADDRen1,
    output logic weADDRen2, //only need one with a not gate
    output logic readMemSel, //0 for mem1, 1 for mem2
    output logic change
);
/*-----------------------INPUT BRIDGE SECTION-------------------------*/
typedef enum logic [1:0]{ //This takes the input which I think I will save to some other RAM
//implemented in a completely different block and this is how the RAM will get into the system
    IDLEIN,
    TRANSIN,
    DONEIN
} states_in;
states_in statein, next_statein;

logic doneIN;
logic [7:0] addressIn;
logic weInput;

always_latch begin
    if(startSigIN) change = 0;
    if(doneIN) change = 1;
end
always @(posedge clk) begin
    statein <= next_statein;
    case(statein) 
        IDLEIN: begin
            doneIN <= 1'd0;
            addressIn <= 8'd255;
            weInput <= 1'd0; 
        end
        TRANSIN:begin
            weInput <= 1'd1; 
            addressIn <= addressIn + 1'd1;
            doneIN <= 1'd0;
        end
        DONEIN: begin
            weInput <= 1'd0; 
            doneIN <= 1'd1;
            addressIn <= 8'd255;
        end
        default: begin
            weInput <= 0; 
            doneIN <= 0;
            addressIn <= 8'd255;
        end
    endcase
end
always_comb begin
    case(statein) 
        IDLEIN: begin
            next_statein = states_in'(startSigIN?TRANSIN:IDLEIN);
        end
        TRANSIN:begin
            next_statein = states_in'((addressIn==6)?DONEIN:TRANSIN);
        end
        DONEIN: begin
            next_statein = IDLEIN;
            //will implement like a state counter to track transmissions complete
        end
        default: begin
            next_statein = IDLEIN;
        end
    endcase
end


/*-----------------------RAM WRITE LOGIC SECTION-------------------------*/
typedef enum logic [1:0] {
    IDLEW,
    WRITE2,//M1R(loading set of data from mem1)MAM2W(writing to next set of data to data 2)
    WRITE1,//same idea just swapped
    DONEW
} states_write;
states_write statew, next_statew;


/*-----------------------RAM READ LOGIC SECTION-------------------------*/
typedef enum logic [1:0] {
    IDLER,
    READ1,//M1R(loading set of data from mem1)MAM2W(writing to next set of data to data 2)
    READ2,//same idea just swapped
    DONER
} states_read;
states_read stater, next_stater;

logic writeComp, readComp; //switch statements for when counters reach specific number
logic [7:0] waddr1Buf, waddr2Buf, raddr1Buf, raddr2Buf, 
waddr1BufP1, waddr1BufP2, waddr2BufP1, waddr2BufP2; //buffers for the outputs just to manipulate
logic [3:0] iteratStep; //this is checking what iteration of FFT we are on.
//combinational transition logic
assign readComp = (raddr1Buf==6||raddr2Buf==6);
assign writeComp = (waddr1Buf==6||waddr2Buf==6);
//output buffers
assign raddr1 = raddr1Buf;
assign raddr2 = raddr2Buf;
assign waddr1 = change?waddr1BufP2:addressIn;
assign waddr2 = waddr2BufP2;
//readmemSel
logic readMemSelBuf, readMemSelBufP1;
assign readMemSel = readMemSelBufP1; //start in read2

logic weADDRen1Buf, weADDRen1BufP1, weADDRen1BufP2, 
weADDRen2Buf, weADDRen2BufP1, weADDRen2BufP2;

assign weADDRen1 = change?weADDRen1BufP2:weInput;
assign weADDRen2 = weADDRen2BufP2;

always_comb begin //state trans block
    case(statew)
        IDLEW: begin
            next_statew = states_write'((doneIN)?WRITE2:IDLEW);
            //all enables 0
        end
        WRITE2: begin
            next_statew = states_write'((writeComp)?WRITE1:WRITE2);
        end
        //possibly include an intermediate state to zero out buffers
        WRITE1: begin
            next_statew = states_write'((writeComp)?((iteratStep==6)?DONEW:WRITE2):WRITE1);
        end
        DONEW: begin
            next_statew = IDLEW;
        end
        default: begin
            next_statew = IDLEW;
        end
    endcase

    case(stater)
        IDLER: begin
            next_stater = states_read'((doneIN)?READ1:IDLER);
        end
        READ1: begin
            next_stater = states_read'((readComp)?READ2:READ1);
        end
        //possibly include an intermediate state to zero out buffers
        READ2: begin
            next_stater = states_read'((readComp)?((iteratStep==6)?DONER:READ1):READ2);
        end
        DONER:begin
            next_stater = IDLER;
        end
        default: begin
            next_stater = IDLER;
        end
    endcase
end
always_ff @(posedge clk) begin //startSignal
    statew <= next_statew;
    stater <= next_stater;
    case(statew)
        IDLEW: begin
            waddr1Buf <= 8'd255;
            waddr2Buf <= 8'd255; 

            weADDRen1Buf <= 1'd0;
            weADDRen2Buf <= 1'd0;          
        end
        WRITE2: begin
            //ram1 counter(read)
            waddr1Buf <= 8'd255;
            waddr2Buf <= waddr2Buf + 1;
            weADDRen1Buf <= 1'd0;//ram2en
            weADDRen2Buf <= 1'd1;
        end
        WRITE1:begin
            //ram1Config
            waddr1Buf <= waddr1Buf + 1;
            waddr2Buf <= 8'd255;

            weADDRen1Buf <= 1'd1;//ram1en
            weADDRen2Buf <= 1'd0;//ram2en
        end
        default: begin
            waddr1Buf <= 8'd255;
            waddr2Buf <= 8'd255;
            weADDRen1Buf <= 1'd0;//ram1en
            weADDRen2Buf <= 1'd0;//ram2en
        end
    endcase

    case(stater)
        IDLER: begin
            raddr1Buf <= 8'd255;
            raddr2Buf <= 8'd255; 
            readMemSelBuf <= 1'd1;
                       
        end
        READ1: begin
            //ram1 counter(read)
            raddr1Buf <= raddr1Buf + 1;
            //ram2Config
            raddr2Buf <= 8'd255;

            readMemSelBuf <= 1'd0;
        end
        READ2:begin
            //ram1Config
            raddr1Buf <= 8'd255;
            //ram2Config
            raddr2Buf <= raddr2Buf + 1;
            readMemSelBuf <= 1'd1;

        end
        default: begin
            raddr1Buf <= 8'd255;
            raddr2Buf <= 8'd255;            
            readMemSelBuf <= 1'd1;
        end
    endcase
    if(readComp) begin
        iteratStep <= iteratStep + 1;
    end
    //pipeline the last writing outputs
    waddr1BufP1 <= waddr1Buf;
    waddr1BufP2 <= waddr1BufP1;

    waddr2BufP1 <= waddr2Buf;
    waddr2BufP2 <= waddr2BufP1;

    weADDRen1BufP1 <= weADDRen1Buf;
    weADDRen1BufP2 <= weADDRen1BufP1;
 
    weADDRen2BufP1 <= weADDRen2Buf;
    weADDRen2BufP2 <= weADDRen2BufP1;
    //readMem at same clock cycle as RAM
    readMemSelBufP1 <= readMemSelBuf;
end

endmodule


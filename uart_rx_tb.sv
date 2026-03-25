`timescale 1ns/1ps
module uart_rx_tb;

    logic rx;
    logic clr;
    logic clock;
    logic[7:0] data;
    logic [15:0] realCounter;
    logic done;

    uart_rx dut (
        .rx(rx),
        .clr(clr),
        .clock(clock),
        .data(data),
        .realCounter(realCounter),
        .done(done)
    );

    initial begin
        clock = 0;
        forever #1 clock = ~clock; 
    end

    initial begin
        $dumpfile("curTest.vcd");
        $dumpvars(0, uart_rx_tb);
        clr = 1;
        #10; 
        clr = 0;
        rx = 1; 
        #100; 
        rx = 1; 
        #100; 
        rx = 1;
        #100;
        //begin transmission
        rx = 0;
         #868;
         rx = 1;
         #868;
         rx = 1;
         #868;
         rx = 1;
         #868
         rx = 0;
         #868
         rx = 0;
         #868
         rx = 1;
         #868
         rx = 1;
         #868
         rx = 0;
         #868
         //STOOP
         rx = 1;
         #2000
         rx = 0;
         #868;
         rx = 1;
         #868;
         rx = 1;
         #868;
         rx = 1;
         #868
         rx = 1;
         #868
         rx = 0;
         #868
         rx = 1;
         #868
         rx = 1;
         #868
         rx = 1;
         #868
         rx = 1;
         #2000
        $finish;
    end
endmodule
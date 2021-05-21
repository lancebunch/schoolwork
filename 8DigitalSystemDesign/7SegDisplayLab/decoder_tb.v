`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/16/2020 04:11:28 PM
// Design Name: 
// Module Name: decoder_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
module decoder_tb();
    reg [3:0] sw;
    wire dp;
    wire [3:0] an;
    wire [6:0] sseg;
    
    SevenSegDisplay U1 (sw, dp, an, sseg);
    
    initial
    begin
    
        $dumpfile("testbench.vcd");
        $dumpvars(0, decoder_tb);
    
        #100 sw = 4'b0000; 
        #100 sw = 4'b0001; 
        #100 sw = 4'b0010; 
        #100 sw = 4'b0011; 
        #100 sw = 4'b0100; 
        #100 sw = 4'b0101; 
        #100 sw = 4'b0110; 
        #100 sw = 4'b0111; 
        #100 sw = 4'b1000; 
        #100 sw = 4'b1001; 
        #100 sw = 4'b1010; 
        #100 sw = 4'b1011; 
        #100 sw = 4'b1100; 
        #100 sw = 4'b1101; 
        #100 sw = 4'b1110;
        #100 sw = 4'b1111; 
        $finish;
    end
    
//    initial
//        $monitor("At time %2t, sw = %d dp = %d an = %d sseg = %d", 
//            $time sw, dp, an, sseg);   
endmodule
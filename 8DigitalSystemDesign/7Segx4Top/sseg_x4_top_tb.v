`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/23/2020 02:31:57 PM
// Design Name: 
// Module Name: sseg_x4_top_tb
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


module sseg_x4_top_tb();
    reg clk, rst; reg [15:0] sw; wire [6:0] seg; wire [3:0] an; wire dp; wire [4:0] JA;
    sseg_x4_top S1(clk, rst, sw, seg, an, dp, JA);
    initial begin
        clk = 1'b0;
        rst = 1'b1;
        #100 rst = 1'b0;
        #100 sw = 16'h0000;
        #100 sw = 16'h0001;
        #100 sw = 16'h0010;
        #100 sw = 16'h0011;
        #100 sw = 16'h0100;
        #100 sw = 16'h0101;
        #100 sw = 16'h0110;
        #100 sw = 16'h0111;
        #100 sw = 16'h1000;
        #100 sw = 16'h1001;
        #100 sw = 16'h1010;
        #100 sw = 16'h1011;
        #100 sw = 16'h1100;
        #100 sw = 16'h1101;
        #100 sw = 16'h1110;
        #100 sw = 16'h1111;
        #100000 $finish;
    end
    
    always #5 clk = !clk;
endmodule

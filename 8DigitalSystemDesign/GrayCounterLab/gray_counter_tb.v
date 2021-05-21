`timescale 1ps / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2020 06:06:27 PM
// Design Name: 
// Module Name: gray_counter_tb
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


module gray_counter_tb();
    reg clk, rst; wire [2:0] led;
    gray_counter_top M0(clk, rst, led);
    
    initial begin
        clk = 1'b0;
        rst = 1'b1;
        forever begin
        #1 clk = ~clk;
    end end
endmodule

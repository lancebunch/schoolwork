`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2020 01:15:12 PM
// Design Name: 
// Module Name: gray_counter_top
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


module gray_counter_top(input clk, input rst, output [2:0] led);
    wire clk_d;
    
    clock_gen M0(clk, rst, clk_d);
    gray_counter M1(clk_d, rst, led);

endmodule

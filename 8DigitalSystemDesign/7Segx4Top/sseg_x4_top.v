`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/23/2020 09:48:48 AM
// Design Name: 
// Module Name: sseg_x4_top
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


module sseg_x4_top(input clk, btnC, input [15:0] sw,
    output [6:0] seg, output [3:0] an, output dp, output [4:0] JA);
    wire clkd;
    wire [3:0] hex_num;
    
    sseg_display M0(.seg(seg), .dp(dp), .sw(hex_num));
    clk_gen M1(clk, btnC, clkd);
    digit_selector M2(clkd, btnC, an);
    hex_num_gen M3(an, sw, hex_num);

    assign JA = {clkd, an};
    
endmodule

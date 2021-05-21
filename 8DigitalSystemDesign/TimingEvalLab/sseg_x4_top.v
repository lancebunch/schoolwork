`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/11/2020 10:42:57 AM
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


module sseg_x4_top(input clk, btnC, input [15:0] sw, output [6:0] seg, output [3:0] an, output dp, output [4:0] JA);
    wire clkd;
    
    wire [3:0] hex_num; // seg and dp are already declared as ports    
    sseg_display U0(
    .seg   (seg),           //  drives the seven LEDs for the display
    .dp    (dp),            //  decimal place assigned permanently to 1'b1
    .sw    (hex_num)        //  can't be called sw any more so I'll call it hex_num
    );
                
    clk_gen U1(clk, btnC, clkd);
    digit_selector U2(clkd, btnC, an);
    hex_num_gen U3(an, sw, hex_num);

    assign JA = {clkd, an};
endmodule

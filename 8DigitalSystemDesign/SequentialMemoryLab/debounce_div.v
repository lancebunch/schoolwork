`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/07/2020 11:06:49 AM
// Design Name: 
// Module Name: debounce_div
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


module debounce_div(input clk, output clk_deb);
    reg [15:0] cnt;
    
    assign clk_deb = cnt[15];
    
    initial cnt = 0;
    always @(posedge clk)
        cnt <= cnt + 1;
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/23/2020 11:39:36 AM
// Design Name: 
// Module Name: digit_selector
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


module digit_selector(input clk, rst, output reg [3:0] digit_sel);
    // Start off by activating the first digit.
    initial begin digit_sel <= 4'b1110; end
    
    // Begin a forever loop. With each push of
    // rst we are going to set the digit selector 
    // back to the 1st digit. Otherwise we shift all
    // of the digits to the left by 1
    always @(posedge clk, posedge rst) begin
        if (rst) digit_sel <= 4'b1110;
        else if (!rst) begin
            digit_sel[3:1] <= digit_sel[2:0];
            digit_sel[0] <= digit_sel[3];
            end
        // Default to save the hardware
        else digit_sel <=4'bxxxx;
    end    
endmodule

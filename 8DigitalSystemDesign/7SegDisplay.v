`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/16/2020 11:20:22 AM
// Design Name: 
// Module Name: SevenSegDisplay
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


module SevenSegDisplay(
    input [3:0] sw,
    output dp,
    output [3:0] an,
    output reg [6:0] seg
    );
    
    // This "opens" AN0 for access to one digit
    // of the 7 segment display
    assign an = 4'b1110;
    // This simply turns off the decimal
    assign dp = 1'b1;
    
    // This is basically a Switch statement using if, else if, and else
    always @(sw)
    begin
        //depending on the switches we will display a hex value on the 7 segment display
        if(sw == 4'h0) seg = 7'b1000000;
        else if (sw == 4'h1) seg = 7'b1111001;
        else if (sw == 4'h2) seg = 7'b0100100;
        else if (sw == 4'h3) seg = 7'b0110000;
        else if (sw == 4'h4) seg = 7'b0011001;
        else if (sw == 4'h5) seg = 7'b0010010;
        else if (sw == 4'h6) seg = 7'b0000010;
        else if (sw == 4'h7) seg = 7'b1111000;
        else if (sw == 4'h8) seg = 7'b0000000;
        else if (sw == 4'h9) seg = 7'b0010000;
        else if (sw == 4'hA) seg = 7'b0001000;
        else if (sw == 4'hB) seg = 7'b0000000;
        else if (sw == 4'hC) seg = 7'b1000110;
        else if (sw == 4'hD) seg = 7'b1000000;
        else if (sw == 4'hE) seg = 7'b0000110;
        else if (sw == 4'hF) seg = 7'b0001110;
        // A default parameter just in case something doesnt match up
        else seg = 7'b1010101;
    end
endmodule

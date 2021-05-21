`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/23/2020 03:01:08 PM
// Design Name: 
// Module Name: hex_num_gen
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


module hex_num_gen(input [3:0] digit_sel, input [15:0] sw, output reg [3:0] hex_num);
    
    // Forever loop
    always @ * begin
        if      (digit_sel == 4'b1110) hex_num = sw[3:0]; //Digit 1
        else if (digit_sel == 4'b1101) hex_num = sw[7:4]; //Digit 2
        else if (digit_sel == 4'b1011) hex_num = sw[11:8];//Digit 3
        else if (digit_sel == 4'b0111) hex_num = sw[15:12];//Digit 4
        else hex_num = 4'bxxxx;
    end
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/11/2020 10:43:53 AM
// Design Name: 
// Module Name: sseg_display
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


module sseg_display(input [3:0] sw, output dp, output [3:0] an, output reg [6:0] seg );
assign an = 4'b1110; assign dp = 1'b1;                   
initial begin seg = 7'b1000000; end

always @(sw)  begin
	if      (sw == 4'b0000) seg = 7'b1000000; // 0
	else if (sw == 4'b0001) seg = 7'b1111001; // 1
	else if (sw == 4'b0010) seg = 7'b0100100; // 2
	else if (sw == 4'b0011) seg = 7'b0110000; // 3
	else if (sw == 4'b0100) seg = 7'b0011001; // 4
	else if (sw == 4'b0101) seg = 7'b0010010; // 5
	else if (sw == 4'b0110) seg = 7'b0000010; // 6
	else if (sw == 4'b0111) seg = 7'b1111000; // 7
	else if (sw == 4'b1000) seg = 7'b0000000; // 8 
	else if (sw == 4'b1001) seg = 7'b0010000; // 9
	else if (sw == 4'b1010) seg = 7'b0001000; // A
	else if (sw == 4'b1011) seg = 7'b0000011; // B
	else if (sw == 4'b1100) seg = 7'b1000110; // C
	else if (sw == 4'b1101) seg = 7'b0100001; // D
	else if (sw == 4'b1110) seg = 7'b0000110; // E
	else if (sw == 4'b1111) seg = 7'b0001110; // F
	else seg = 7'bXXXXXXX;  //don't care for simulation
end //always

endmodule

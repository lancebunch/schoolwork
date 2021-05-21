`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/23/2020 11:56:25 AM
// Design Name: 
// Module Name: decoder
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


module decoder(
    input [2:0] sw,
    output reg [7:0] led
    );
    
    always @ (sw)
        case (sw)
            3'b000: led = 8'h01;
            3'b001: led = 8'h02;
            3'b010: led = 8'h04;
            3'b011: led = 8'h08;
            3'b100: led = 8'h10;
            3'b101: led = 8'h20;
            3'b110: led = 8'h40;
            3'b111: led = 8'h80;
        endcase
endmodule

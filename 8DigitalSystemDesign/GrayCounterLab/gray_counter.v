`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2020 01:03:41 PM
// Design Name: 
// Module Name: gray_counter
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
module gray_counter(input clk, input rst, output reg [2:0] led);
    reg A, B, C; //used as a "current state" for gray code

    initial begin led = 3'b000; end
    begin // Initializing current state and next state cases
        initial C = led[0];
        initial B = led[1];
        initial A = led[2];
    end
    // With Every clock or rst, increment gray code or reset system
    always @ (posedge clk or posedge rst) begin
        if (rst) begin
            led = 3'b000;
            begin
                C <= led[0];
                B <= led[1];
                A <= led[2];
            end
        end
        else begin
            led[2] = (!B && C) || (B && !C);
            led[1] = (!A && B) || (A && C);
            led[0] = (!A && !B) || (A && C);
            begin
                C <= led[0];
                B <= led[1];
                A <= led[2];
            end
        end
    end
endmodule

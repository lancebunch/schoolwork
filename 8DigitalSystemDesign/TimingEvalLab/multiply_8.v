`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/11/2020 10:53:09 AM
// Design Name: 
// Module Name: multiply_8
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
module multiply_8(input clk, input wire [15:0] a, output reg [15:0] m);
    wire [7:0] b; assign b = a[15:8];
    wire [15:0] p0, p1, p2, p3, p4, p5, p6, p7;
    reg [15:0] s0, s1, s2, s3, s4, s5;
       
    // ands  A to B and shifts it a certian amount
    
    assign p0 = {({8{a[0]}} & b[7:0])}; 
    assign p1 = {({8{a[1]}} & b[7:0]), 1'h00}; 
    assign p2 = {({8{a[2]}} & b[7:0]), 2'h00};
    assign p3 = {({8{a[3]}} & b[7:0]), 3'h00};
    assign p4 = {({8{a[4]}} & b[7:0]), 4'h00};
    assign p5 = {({8{a[5]}} & b[7:0]), 5'h00};
    assign p6 = {({8{a[6]}} & b[7:0]), 6'h00}; 
    assign p7 = {({8{a[7]}} & b[7:0]), 7'h00};
    
    //adds up all the shifted and anded results
    always @(posedge clk) begin
        s0 <= p0 + p1;
        s1 <= p2 + p3;
        s2 <= p4 + p5;
        s3 <= p6 + p7; 
        s4 <= s0 + s1;
        s5 <= s2 + s3;
        m  <= s4 + s5; end
endmodule

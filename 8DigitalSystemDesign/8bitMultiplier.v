`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Lance Bunch
// 
// Create Date: 10/09/2020 11:37:06 AM
// Design Name: 
// Module Name: 8bitMultiplier
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


module multiplier(
    // Establishing inputs and outputs
    input [7:0] top,            //ex.  101 (this is my top input)
    input [7:0] bottom,         //   x 001 (this is my bottom input)
    output [15:0] product       //This is used as the final product
    );
    
    // 8-16 bit wires to represent each place of a potential binary output
    wire [15:0] p0, p1, p2, p3, p4, p5, p6, p7;
    
    //ex.   0000 1010
    //    x 0000 1110
    //p0 = (0 * 0) + (0 * 1) ...
    //p1 = (1 * 0) + (1 * 1) ... shifted to the left 1 bit (multiplied by 2)
    //p2 = (1 * 0) + (1 * 1) ... shifted to the left 2 bit (multiplied by 4)
    //This pattern continues accross the rest of the bits until p0 - p7 are 
    //all discoverd
    assign p0[7:0]  = ({8{bottom[0]}} & top[7:0]);
    assign p1[8:0]  = {({8{bottom[1]}} & top[7:0]), 1'b0};
    assign p2[9:0]  = {({8{bottom[2]}} & top[7:0]), 2'b00};
    assign p3[10:0] = {({8{bottom[3]}} & top[7:0]), 3'b000};
    assign p4[11:0] = {({8{bottom[4]}} & top[7:0]), 4'b0000};
    assign p5[12:0] = {({8{bottom[5]}} & top[7:0]), 5'b00000};
    assign p6[13:0] = {({8{bottom[6]}} & top[7:0]), 6'b000000};
    assign p7[14:0] = {({8{bottom[7]}} & top[7:0]), 7'b0000000};
    
    //After we have gotten p0-p7, we add them together to get 
    //the final product
    assign product = p0 + p1 + p2 + p3 + p4 + p5 + p6 + p7;
endmodule

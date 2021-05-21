`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/02/2020 11:24:35 AM
// Design Name: 
// Module Name: add8
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


module add8(
    input [15:0] sw,
    output [8:0] led
    );
    
    //These are carryout wires to connect each individual adder together
    wire c1, c2, c3, c4, c5, c6, c7;
    
    //instantiating 8 adders
    //        Cin,    x,    y,      s,        Co
    adder a1(1'b0, sw[0], sw[8],  led[0],     c1);
    adder a2  (c1, sw[1], sw[9],  led[1],     c2);
    adder a3  (c2, sw[2], sw[10], led[2],     c3);
    adder a4  (c3, sw[3], sw[11], led[3],     c4);
    adder a5  (c4, sw[4], sw[12], led[4],     c5);
    adder a6  (c5, sw[5], sw[13], led[5],     c6);
    adder a7  (c6, sw[6], sw[14], led[6],     c7);
    adder a8  (c7, sw[7], sw[15], led[7], led[8]);
    
endmodule

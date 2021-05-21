`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: BYU-I
// Engineer: Lance Bunch
// 
// Create Date: 10/02/2020 10:57:26 AM
// Design Name: 8-Bit Adder
// Module Name: adder
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


module adder(
    input Cin,
    input x,
    input y,
    output s,
    output Co
    );
    
    //wires serving as outputs for the AND gates
    wire z1, z2, z3;
    
    // XOR x, y, and cin. If 2 inputs are true the output will 
    // be false, if 1 or all 3 inputs are true the output will be true
    // This merely determines whether or not the LED will turn on
    xor(s, x, y, Cin);
    
    // These AND gates are used to determine the sum of
    // 2 inputs. We AND every possible input combination.
    and(z1, x, y),
       (z2, x, Cin),
       (z3, y, Cin);
       
    // This determines if we have a carryout to the next adder
    or(Co, z1, z2, z3);
    
endmodule

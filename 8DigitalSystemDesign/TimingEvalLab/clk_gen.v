`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/11/2020 10:44:56 AM
// Design Name: 
// Module Name: clk_gen
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


module clk_gen(input clk, rst, output clk_div);
    reg [26:0] counter;
    assign clk_div = counter[18]; //use bit 2 for sim then 18 for implementation
    
    initial begin counter <= 27'b000000000000000000000000000; end
    
    always @ (posedge clk, posedge rst)
    begin
        if (rst)      counter <= 27'b000000000000000000000000000;
        else if(!rst) counter <= counter + 1'b1;
        else          counter <= 27'bxxxxxxxxxxxxxxxxxxxxxxxxxxx;
    end
endmodule

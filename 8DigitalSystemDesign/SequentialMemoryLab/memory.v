`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/07/2020 10:53:34 AM
// Design Name: 
// Module Name: memory
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


module memory(inout [15:0] data, input oe, input we, input clk, input [14:0] addr);
    reg [15:0] mem [0:32767]; reg [15:0] data_temp;
    assign data = (oe && !we) ? data_temp : 16'hzzzz;
    always@(posedge clk) begin 
        if (we) mem[addr] <= data; 
        else if (oe) data_temp <= mem[addr]; end 
endmodule

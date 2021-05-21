`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/11/2020 10:45:52 AM
// Design Name: 
// Module Name: digit_selector
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


module digit_selector(input clk, rst, output reg [3:0] digit_sel);
    initial begin digit_sel <= 4'b1110; end
    
    always@(posedge clk, posedge rst)
        begin
            if (rst) digit_sel <= 4'b1110;
            else if (!rst) begin 
            digit_sel[3:1] <= digit_sel[2:0];
            digit_sel[0]   <= digit_sel[3];
            //digit_sel    <= {digit_sel[2:0], digit_sel[3]};  another way to shift.
            end 
            else digit_sel <= 4'bXXXX; 
        end
endmodule

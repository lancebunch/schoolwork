`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/11/2020 10:47:24 AM
// Design Name: 
// Module Name: btn_debounce
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


module btn_debounce(input clk, input btn_in, output wire btn_status);
    reg [19:0] btn_shift;
        
    always @ (posedge clk)
        btn_shift <= {btn_shift[18:0], btn_in};
    
    assign btn_status = &btn_shift;
endmodule

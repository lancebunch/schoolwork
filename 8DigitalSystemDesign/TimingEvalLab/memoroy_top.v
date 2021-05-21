`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/11/2020 10:40:44 AM
// Design Name: 
// Module Name: memoroy_top
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


module memoroy_top(
    input clk,          //100MHz clk.
    input [15:0] sw,    //Data for input memory.
    input btnC,         //Execute button. It is used concurrently with other buttons.
    input btnU,         //Manually Increment the memory address by one.
    input btnD,         //Manually decrement the memory address by one.
    input btnL,         //Select the input memory bank.
    input btnR,         //Select the output memory bank.
    output [3:0] an,    //The anode drivers for the 7-seg display.
    output [6:0] seg,   //The 7-segments. It is used to display the data in memory.
    output dp,          //The decimal place on the 7-seg display.
    output [15:0] led   //The 16 leds are used to display the address information and the mode information.
    );
    
    wire [15:0] data_in_mem;   //Data for the input memory bank.
    wire [15:0] data_out_mem;  //Data for the output memory bank.
    wire [15:0] sum_data;      //The sum of the two halves of the input memory data.  It is stored in the output memory bank.
    wire clk_deb;              //The debouncer clock (100MHz/(2^16).
    wire inc_addr, dec_addr;   //Increment/decrement the memory address by one or clear the address.
    wire sel_input, sel_output;//Select the input or output memory bank.
    wire execute;              //Execute is combined with other buttons to perform a task.
    
    reg wr_in_mem, rd_in_mem;       //Read and write mode for the input memory bank.
    reg wr_out_mem, rd_out_mem;     //Read and write mode for the output memory bank.
    reg we_in, we_out;              //Write enables for the input and output memory banks.
    reg oe_in, oe_out;              //Output enables for the input and output memory banks.
    reg [15:0] disp_data;           //Data sent to the 7-segment display.
    reg sel_in_mem;                 //Registerred memory bank select.
    reg inc_addr_one, dec_addr_one; //Address operations
    reg rst_addr, inc_addr_all;     //Address operations   
    reg inc_addr_tm1, dec_addr_tm1; //Address operations (delayed by one clock cycle)
    reg [3:0] addr, addr_out_mem;   //Address for input and output memory locations.
                                    //The output memory address lags the input address by one clock cycle
 
    sseg_x4_top u2 (.clk(clk), .btnC(1'b0), .sw(disp_data), .seg(seg), .an(an), .dp(dp));
    memory in_mem (.we(we_in), .oe(oe_in), .clk(clk), .data(data_in_mem), .addr(addr));
    memory out_mem (.we(we_out), .oe(oe_out), .clk(clk), .data(data_out_mem), .addr(addr_out_mem));
    debounce_div div1 (.clk(clk), .clk_deb(clk_deb));
    btn_debounce up (.clk(clk_deb), .btn_in(btnU), .btn_status(inc_addr));
    btn_debounce down (.clk(clk_deb), .btn_in(btnD), .btn_status(dec_addr));
    btn_debounce left (.clk(clk_deb), .btn_in(btnL), .btn_status(sel_input));
    btn_debounce right (.clk(clk_deb), .btn_in(btnR), .btn_status(sel_output));
    btn_debounce center (.clk(clk_deb), .btn_in(btnC), .btn_status(execute));   
    
    assign data_in_mem = we_in?sw:16'hZZZZ;     //If we_in is enabled then store data from switches to data_in_mem. Otherwise,
      //set switch inputs to high impedance inside the chip so that the memory can drive the bi-directional bus.
    multiply_8 mult(clk, sw, sum_data);
    //assign sum_data = data_in_mem[15:8] + data_in_mem[7:0]; //Change for Lab 6      //Contimuously add the contents of the data_in_mem halves.
      //The objective is to add the data coming out of the input memory since this is a bi-directional bus.  It turns out 
      //that the data going into the memory will also be added.  This does not hurt anything (for now), but consider
      //blocking this addition unless the oe_in is enabled.
    assign data_out_mem = we_out?sum_data:16'hZZZZ;    //If we_out is enabled then store the summed data into the output memory. 
      //Otherwise, the sum_data bus is set to high impedance inside the chip so that the output memory can drive that bi-directional
      // bus to light the seven segment display.
    assign led[3:0] = addr; // show the address on the four, least significant LEDs.
    assign led[7:4] = 4'b0000; // unused LEDs
    assign led[15:8] = {wr_in_mem, rd_in_mem, wr_out_mem, rd_out_mem, we_in, oe_in, we_out, oe_out}; // debug LEDs
    

    always @ (execute, sel_input, sel_in_mem, sel_output)  //Input and output memory mode configuration
    begin 
      wr_in_mem = execute && sel_input;    //"execute" is the de-bounced center button, "sel_input" is the debounced left button.
                                           //When both buttons are pressed, configure the memory busses so it is possible to
                                           //write to the input memory.
      rd_in_mem = !execute && sel_in_mem;  //"sel_in_mem" is the registerred version of "sel_input" (it doesn't go away when the
                                           //button is released). It is generated from a set/reset flip flop.
      wr_out_mem = execute && sel_output;  //When both "execute" (center button) and "set_output" (right button) are pressed,
                                           //configure the memory busses so it is possible to write to the output memory.
      rd_out_mem = !execute && !sel_in_mem;//"sel_in_mem" is registerred "false" when "sel_output" (right button is pressed).
                                           //Here we only have two states: select input memory, or select output memory.
      
      if (wr_in_mem)  //configure the memory busses so it is possible to write to the input memory bank.
      begin
        we_in = 1'b1;
        oe_in = 1'b0;
        we_out = 1'b0;
        oe_out = 1'b0;
      end
      else if (rd_in_mem) //configure the memory busses so it is possible to read from the input memory bank.
      begin
        we_in = 1'b0;
        oe_in = 1'b1;
        we_out = 1'b0;
        oe_out = 1'b0;
      end
      else if (wr_out_mem) //configure the memory busses so it is possible to write to the output memory bank.
      begin
        we_in = 1'b0;
        oe_in = 1'b1;      //enable the output of the input memory bank so it can drive the adder, which drives the input to the
                           //output memory bank
        we_out = 1'b1;
        oe_out = 1'b0;
      end
      else if (rd_out_mem)  //configure the memory busses so it is possible to read from the output memory bank.
      begin
        we_in = 1'b0;
        oe_in = 1'b0;
        we_out = 1'b0;
        oe_out = 1'b1;
      end
      else
      begin
        we_in = 1'b0;       //default
        oe_in = 1'b0;
        we_out = 1'b0;
        oe_in = 1'b0;
      end
    end
      
    always @ (sel_in_mem, data_in_mem, data_out_mem) //Selecting the display data
    begin
      if (sel_in_mem)   //"sel_in_mem is registered so after the right or left buttons are pressed, the state is rememberred
          disp_data = data_in_mem;
      else
          disp_data = data_out_mem;

    end
    
    always @ (posedge clk, posedge sel_output, posedge sel_input) begin //Registerring the input/output memory bank buttons
      if (sel_output) sel_in_mem <= 1'b0;
      else if (sel_input) sel_in_mem <= 1'b1; end
    
    always @ (inc_addr, inc_addr_tm1, execute, sel_output, dec_addr, dec_addr_tm1) // Address operations
    begin
      inc_addr_one = inc_addr && !inc_addr_tm1;  //Generates a single increment pulse (lasting one clock cycle) no matter 
                                                 //how long the increment button is pressed.
      dec_addr_one = dec_addr && !dec_addr_tm1;  //Generates a single decrement pulse (lasting one clock cycle).
      inc_addr_all = sel_output && execute;      //While these two buttons are pressed simultaneously, "in_addr_all" remains true.
                                                 //This is not a pulse.
      rst_addr = inc_addr && dec_addr;           //Pressing these two buttons resets the address.
    end
    
    always @ (posedge clk) //Address signals delayed by one clock cycle.
    begin
      inc_addr_tm1 <= inc_addr;  //Create a delayed version of "inc_addr" so an increment pulse may be generated.
      dec_addr_tm1 <= dec_addr;  //Create a delayed version of "dec_addr" so a decrement pulse may be generated.
      addr_out_mem <= addr;      //Create a delayed version of "addr" for the output memory address so that the 
                                 //input and output memory blocks align (the sum is written one clock cycle after 
                                 //the input memory block is read).
    end
    
    initial addr = 4'h0;   //Address generator implementation
    always @ (posedge clk) begin
        if (rst_addr) addr <= 4'h0;
        else if (dec_addr_one && (addr > 4'h0)) addr <= addr - 1;
        else if ((inc_addr_one || inc_addr_all) && (addr < 4'hF)) addr <= addr + 1;
    end
endmodule

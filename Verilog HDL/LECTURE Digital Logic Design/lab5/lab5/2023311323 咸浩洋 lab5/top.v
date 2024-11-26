`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2024/11/14 16:11:30
// Design Name:
// Module Name: top
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


module top(

    input wire clk,
    input wire rst,
    //send
    input wire S3,
    input [7:0] sw,
    output wire dout,
    //recv
    input din,
    output [7:0] led_en,
    output [7:0] led
  );

  led u_led(
        .clk(clk),
        .rst(rst),
        .din(din),
        .led_en(led_en),
        .led(led)
      );

  sw_display u_sw_display(
               .clk(clk),
               .rst(rst),
               .sw(sw),
               .S3(S3),
               .dout(dout)
             );
endmodule

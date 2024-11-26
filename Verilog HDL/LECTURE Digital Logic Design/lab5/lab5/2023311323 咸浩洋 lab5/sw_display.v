`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2024/11/13 14:20:17
// Design Name:
// Module Name: sw_display
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


module sw_display(
    input clk,
    input rst,
    input S3,
    input [7:0] sw,
    output wire dout
  );

  reg [7:0] data;
  reg valid;
  wire [7:0]sw_out;
  reg [7:0] sw_in;

  reg [31:0] timer_div_10ms;
  reg [1:0] limit_div_10ms = 0;

  reg S3_before;
  wire button_posedge;

  always @(posedge clk or posedge rst or posedge button_posedge)
  begin //10ms 按键去抖动
    if (rst)
    begin
      S3_before <= 0;
      timer_div_10ms <= 0;
      limit_div_10ms <= 0;
    end
    else
    begin
      S3_before <= S3;
      if (button_posedge)
      begin
        timer_div_10ms <= 0;
        limit_div_10ms <= 0;
      end
      else
      begin
        timer_div_10ms <= timer_div_10ms + 1;
        if (timer_div_10ms == 10000000)
          //if (timer_div_10ms == 10000000)
        begin
          limit_div_10ms <= 1;
        end
      end
    end
  end
  assign button_posedge = (S3 & ~S3_before);

  always@ (posedge limit_div_10ms or posedge rst)
  begin
    if(rst)
    begin
      valid <= 0;
      data <= 0;
    end
    else
    begin
      if (S3)
      begin
        valid <= 1;
        data <= sw_in;
      end
      else
      begin
        valid <= 0;
      end
    end
  end


  always@(*)
  begin
    sw_in = sw_out;
  end


  sw_cnt u_sw_cnt(
           .clk(clk),
           .rst(rst),
           .out(sw_out),
           .sw(sw)
         );

  uart_send u_uart_send(
              .clk(clk),
              .rst(rst),
              .valid(valid),
              .data(data),
              .dout(dout)
            );
endmodule

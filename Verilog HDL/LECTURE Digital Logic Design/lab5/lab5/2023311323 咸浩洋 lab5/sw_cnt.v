`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2024/11/13 15:50:39
// Design Name:
// Module Name: sw_cnt
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


module sw_cnt(
    input wire clk,
    input wire rst,
    input wire[7:0] sw,
    output reg[7:0] out
  );

  integer i;

  always @(posedge clk or posedge rst)
  begin
    if(rst)
      out = 8'b0000_0000;
    else
    begin
      out = 8'b0000_0000;
      for(i = 0;i < 8;i = i + 1)
        if(sw[i])
          out[i] = 1;
        else
          out[i] = 0;
    end
  end

endmodule

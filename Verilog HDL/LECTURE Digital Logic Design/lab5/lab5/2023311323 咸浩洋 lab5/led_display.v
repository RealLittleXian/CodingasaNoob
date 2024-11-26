`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2024/11/13 15:45:07
// Design Name:
// Module Name: led_display
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

module display(
    input wire       clk,
    input wire       rst,
    input [31:0] data,
    input [7:0] led_cnt,
    output reg [7:0] led_en,
    output reg [7:0] led
  );

  reg  time_step;
  reg  time_end;
  reg [24:0] time_cnt;
  reg [7:0] tdata[7:0];
  integer i;

  always @(*)
  begin
    for(i=0;i<8;i = i + 1)
    begin
      if(led_cnt[i])
      begin
        case(data[(4*i)+:4])
          4'b0000:
            tdata[i] = 8'b1100_0000;   // 0
          4'b0001:
            tdata[i] = 8'b1111_1001;   // 1
          4'b0010:
            tdata[i] = 8'b1010_0100;   // 2
          4'b0011:
            tdata[i] = 8'b1011_0000;   // 3
          4'b0100:
            tdata[i] = 8'b1001_1001;   // 4
          4'b0101:
            tdata[i] = 8'b1001_0010;   // 5
          4'b0110:
            tdata[i] = 8'b1000_0010;   // 6
          4'b0111:
            tdata[i] = 8'b1111_1000;   // 7
          4'b1000:
            tdata[i] = 8'b1000_0000;   // 8
          4'b1001:
            tdata[i] = 8'b1001_1000;   // 9
          4'b1010:
            tdata[i] = 8'b1000_1000;   // A
          4'b1011:
            tdata[i] = 8'b1000_0011;   // B
          4'b1100:
            tdata[i] = 8'b1010_0111;   // C
          4'b1101:
            tdata[i] = 8'b1010_0001;   // D
          4'b1110:
            tdata[i] = 8'b1000_0110;   // E
          4'b1111:
            tdata[i] = 8'b1000_1110;   // F
          // 报告中省略其他case
          default:
            tdata[i] = 8'b1111_1111;
        endcase
      end
      else
      begin
        tdata[i] = 8'b1111_1111;
      end
    end
  end
  always @(*)
  begin
    time_end = (time_cnt == 20'd100000) & time_step;
  end

  always @(posedge clk or posedge rst)
  begin
    if (rst)
      time_step <= 1'b1;
    else
      time_step <= 1'b1;
  end

  always @(posedge clk or posedge rst)
  begin
    if (rst)
      time_cnt <= 1'b0;
    else if(time_end)
      time_cnt <= 1'b0;
    else
      time_cnt <= time_cnt + time_step;
  end

  always @(posedge clk)
  begin
    if (rst)
      led_en <= 8'b1111_1111;
    if (led_en == 8'b1111_1111 && ~rst)
      led_en <= 8'b0111_1111;
    if (time_end)
    begin
      led_en <= {led_en[6:0], led_en[7]};
    end
  end

  always @(posedge clk)
  begin
    if (rst)
      led <= 8'b1111_1111;
    case (led_en)
      8'b0111_1111:
        led <= tdata[0];
      8'b1011_1111:
        led <= tdata[1];
      8'b1101_1111:
        led <= tdata[2];
      8'b1110_1111:
        led <= tdata[3];
      8'b1111_0111:
        led <= tdata[4];
      8'b1111_1011:
        led <= tdata[5];
      8'b1111_1101:
        led <= tdata[6];
      8'b1111_1110:
        led <= tdata[7];
      default:
        led <= 8'b1111_1111;
    endcase
  end

endmodule


`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2024/11/14 16:18:01
// Design Name:
// Module Name: led
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


module led(
    input clk,
    input rst,
    input din,
    output reg [7:0] led_en,
    output reg [7:0] led
  );

  wire [7:0] data;
  wire valid;
  reg [31:0] data_to_send;
  wire [7:0] _led_en;
  wire [7:0] _led;
  reg[7:0] led_cnt;

  always@(posedge clk or posedge rst)
  begin
    if(rst)
    begin
      data_to_send <= 32'b0;
      led_cnt <= 8'b0;
    end
    else
    begin
      if(valid)
      begin
        case (data)
          8'h30:
          begin
            data_to_send <= {data_to_send[27:0],4'b0000};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h31:
          begin
            data_to_send <= {data_to_send[27:0],4'b0001};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h32:
          begin
            data_to_send <= {data_to_send[27:0],4'b0010};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h33:
          begin
            data_to_send <= {data_to_send[27:0],4'b0011};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h34:
          begin
            data_to_send <= {data_to_send[27:0],4'b0100};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h35:
          begin
            data_to_send <= {data_to_send[27:0],4'b0101};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h36:
          begin
            data_to_send <= {data_to_send[27:0],4'b0110};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h37:
          begin
            data_to_send <= {data_to_send[27:0],4'b0111};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h38:
          begin
            data_to_send <= {data_to_send[27:0],4'b1000};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h39:
          begin
            data_to_send <= {data_to_send[27:0],4'b1001};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h41:
          begin
            data_to_send <= {data_to_send[27:0],4'b1010};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h42:
          begin
            data_to_send <= {data_to_send[27:0],4'b1011};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h43:
          begin
            data_to_send <= {data_to_send[27:0],4'b1100};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h44:
          begin
            data_to_send <= {data_to_send[27:0],4'b1101};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h45:
          begin
            data_to_send <= {data_to_send[27:0],4'b1110};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h46:
          begin
            data_to_send <= {data_to_send[27:0],4'b1111};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h61:
          begin
            data_to_send <= {data_to_send[27:0],4'b1010};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h62:
          begin
            data_to_send <= {data_to_send[27:0],4'b1011};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h63:
          begin
            data_to_send <= {data_to_send[27:0],4'b1100};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h64:
          begin
            data_to_send <= {data_to_send[27:0],4'b1101};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h65:
          begin
            data_to_send <= {data_to_send[27:0],4'b1110};
            led_cnt <= led_cnt << 1 | 1;
          end
          8'h66:
          begin
            data_to_send <= {data_to_send[27:0],4'b1111};
            led_cnt <= led_cnt << 1 | 1;
          end
          // 报告中省略其他case
          default:
            led_cnt <= led_cnt << 1 | 1;
        endcase
      end
    end
  end

  always @(*)
  begin
    led_en = _led_en;
    led = _led;
  end

  display u_display(
            .clk(clk),
            .rst(rst),
            .data(data_to_send),
            .led_cnt(led_cnt),
            .led(_led),
            .led_en(_led_en)
          );
  uart_recv u_uart_recv(
              .clk(clk),
              .rst(rst),
              .valid(valid),
              .data(data),
              .din(din)
            );
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

`define max_clk_cnt 10000000

module my_uart(
    input clk,
    input rst,
    output wire dout
  );

  reg[7:0] data_to_send[0:9];
  reg[3:0] cur_num = 0;
  reg[31:0] clk_cnt = 1;

  reg valid;
  reg[7:0] data;
  uart_send u_uart_send(
              .clk(clk),
              .rst(rst),
              .valid(valid),
              .data(data),
              .dout(dout)
            );

  initial
  begin
    data_to_send[0] = 8'h32;
    data_to_send[1] = 8'h30;
    data_to_send[2] = 8'h32;
    data_to_send[3] = 8'h33;
    data_to_send[4] = 8'h33;
    data_to_send[5] = 8'h31;
    data_to_send[6] = 8'h31;
    data_to_send[7] = 8'h33;
    data_to_send[8] = 8'h32;
    data_to_send[9] = 8'h33;
  end

  always @(posedge clk or posedge rst)
  begin
    if (rst)
    begin
      valid <= 0;
      data <= 8'h00;
      cur_num <= 0;
      clk_cnt <= 1;
    end
    else
    begin
      if (clk_cnt == 1)
      begin
        valid <= 1;
        data <= data_to_send[cur_num];
      end
      else
      begin
        valid <= 0;
      end
      if (clk_cnt < `max_clk_cnt)
      begin
        clk_cnt <= clk_cnt + 1;
      end
      else
      begin
        clk_cnt <= 1;
        if (cur_num < 9)
        begin
          cur_num <= cur_num + 1;
        end
        else
        begin
          cur_num <= 0;
        end
      end
    end
  end

endmodule

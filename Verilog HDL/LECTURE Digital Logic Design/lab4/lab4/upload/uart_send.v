`timescale 1ns / 1ps

`define bit_clk_cnt 10416

module uart_send(
    input        clk,
    input        rst,
    input        valid,       // indicates data is valid ��logic high (1)��, last one clock
    input [7:0]  data,        // data to send
    output reg   dout         // connect to usb_uart tx pin
  );

  localparam IDLE  = 2'b00;
  localparam START = 2'b01;
  localparam DATA  = 2'b10;
  localparam STOP  = 2'b11;

  reg [31:0] clk_cnt;
  reg [3:0] bit_index;
  reg [1:0] cur_state, next_state;
  reg [7:0] data_reg;

  always @(posedge clk or posedge rst)
  begin
    if(rst)
    begin
      data_reg <= 0;
      clk_cnt <= 0;
      bit_index <= 0;
    end
    else
    begin
      if(valid)
      begin
        data_reg <= data;
        bit_index <= 0;
      end
      else if(clk_cnt == `bit_clk_cnt && cur_state == DATA)
      begin
        bit_index <= bit_index + 1;
      end
      if (clk_cnt == `bit_clk_cnt || valid)
      begin
        clk_cnt <= 0;
      end
      else
      begin
        clk_cnt <= clk_cnt + 1;
      end
    end
  end

  always @(posedge clk or posedge rst)
  begin
    if(rst)
      cur_state <= IDLE;
    else
      cur_state <= next_state;
  end

  always @(*)
  begin
    case (cur_state)
      IDLE:
        if (valid)
          next_state = START;
        else
          next_state = IDLE;
      START:
        if (clk_cnt == `bit_clk_cnt)
          next_state = DATA;
        else
          next_state = START;
      DATA:
        if (clk_cnt == `bit_clk_cnt && bit_index == 7)
          next_state = STOP;
        else
          next_state = DATA;
      default:
        next_state = IDLE;
    endcase
  end

  always @(posedge clk or posedge rst)
  begin
    if(rst)
      dout <= 1;
    else
    begin
      case(cur_state)
        START :
          dout <= 0;
        DATA :
          dout <= data_reg[bit_index];
        default :
          dout <= 1;
      endcase
    end
  end

endmodule

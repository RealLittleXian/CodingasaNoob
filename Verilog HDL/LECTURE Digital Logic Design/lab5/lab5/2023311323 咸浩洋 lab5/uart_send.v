`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2024/11/05 14:38:41
// Design Name:
// Module Name: uart_send
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


module uart_send(
    input        clk,
    input        rst,
    input        valid,
    input [7:0]  data,
    output reg   dout
  );


  localparam IDLE  = 2'b00;
  localparam START = 2'b01;
  localparam DATA  = 2'b10;
  localparam STOP  = 2'b11;

  localparam BAUD_RATE = 9600;
  localparam SYS_CLK_FREQ = 100_000_000;
  localparam BAUD_TICKS = SYS_CLK_FREQ / BAUD_RATE;

  reg [1:0] state, next_state;
  reg [3:0] bit_count;
  reg [31:0] baud_counter;
  reg [7:0] data_to_send;


  always @(*)
  begin
    case (state)
      IDLE:
      begin
        if (valid)
        begin
          next_state = START;
        end
        else
        begin
          next_state = IDLE;
        end
      end
      START:
      begin
        if(baud_counter== 0)
        begin
          next_state = DATA;
        end
        else
        begin
          next_state = START;
        end
      end
      DATA:
      begin
        if (bit_count == 8)
        begin
          next_state = STOP;
        end
        else
        begin
          next_state = DATA;
        end
      end
      STOP:
      begin
        if(baud_counter==0)
        begin
          next_state = IDLE;
        end
        else
        begin
          next_state = STOP;
        end
      end
      default:
      begin
        if(valid)
        begin
          next_state = START;
        end
      end
    endcase
  end


  always @(posedge clk or posedge rst)
  begin
    if (rst)
    begin
      state <= IDLE;
      bit_count <= 4'd0;
      baud_counter <= 32'd0;
      data_to_send <= 8'd0;
    end
    else
    begin
      if (baud_counter == 0)
      begin
        if (state == DATA)
        begin
          bit_count <= bit_count + 1;
          data_to_send <= {1'b0,data_to_send[7:1]}; 
          baud_counter <= BAUD_TICKS - 1;
        end
        else if (state == START)
        begin
          baud_counter <= BAUD_TICKS - 1;
          bit_count <= 4'd0;
        end
        else if(state==IDLE)
        begin
          if(valid)
          begin
            data_to_send <= data;
            baud_counter = BAUD_TICKS - 1;
          end
        end
      end
      else
      begin
        baud_counter <= baud_counter - 1;
      end
      state <= next_state;
    end
  end


  always @(posedge clk or posedge rst)
  begin
    if (rst)
    begin
      dout <= 1'b1;
    end
    else
    begin
      case (state)
        IDLE:
        begin
          dout <= 1'b1;
        end
        START:
        begin
          dout <= 1'b0;
        end
        DATA:
        begin
          dout <= data_to_send[0];
        end
        STOP:
        begin
          dout <= 1'b1;
        end
      endcase
    end
  end

endmodule

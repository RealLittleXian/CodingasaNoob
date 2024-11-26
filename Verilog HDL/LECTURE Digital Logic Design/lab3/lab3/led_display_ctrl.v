`timescale 1ns / 1ps

module led_display_ctrl
  (
    input clk,          // 时钟信号
    input rst,        // 异步复位信号
    input [7:0] sw,      // 拨码开关输入
    input button_count,           // 计数按键
    input button_dec_counter,           // 十进制计数器控制信号
    output reg [7:0] led_en, // 数码管使能信号
    output reg [7:0] led_cx  // 数码管段选信号
  );


  reg [10:0] count;       // 计数器
  reg [4:0] dec_count;   // 十进制计数器
  reg [3:0] sum; // 拨码开关中1的个数
  reg [10:0] data[7:0];// 存储数码管显示的数据
  reg [10:0] p;
  reg [31:0] count_1;

  reg [3:0] button_counter1; // 按键计数
  reg [3:0] button_counter0;
  reg [3:0] dec_counter1; // 十进制计数器
  reg [3:0] dec_counter0;

  reg [31:0] timer_100ms;
  reg [31:0] timer_div_10ms;
  reg [1:0] limit_div_10ms = 0;

  reg button_count_before;
  wire button_posedge;

  always @ (posedge clk or posedge rst)
  begin
    if(rst)
    begin
      p<=0;
      count_1<=1'd0;
      led_en<=8'b11111110;
      data[7] <= 4'd2;
      data[6] <= 4'd3;
    end
    else if(count_1>= 200000)
    begin
      count_1<= 0;
      p<=(p+1)%8;
      led_en<={led_en[6:0],led_en[7]};
    end
    else
      count_1<=count_1+1;
  end

  //开关打开计数
  always@*
  begin
    sum = sw[0]+sw[1]+sw[2]+sw[3]+sw[4]+sw[5]+sw[6]+sw[7];
    data[7] <= 4'd2;
    data[6] <= 4'd3;
    data[5]<=sum/10;
    data[4]<=sum%10;
    data[3]<=button_counter1;
    data[2]<=button_counter0;
    data[1]<=dec_counter1;
    data[0]<=dec_counter0;
  end

  always @(posedge clk or posedge rst or posedge button_posedge)
  begin //10ms 按键去抖动
    if (rst)
    begin
      button_count_before <= 0;
      timer_div_10ms <= 0;
      limit_div_10ms <= 0;
    end
    else
    begin
      button_count_before <= button_count;
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
  assign button_posedge = (button_count & ~button_count_before);

  always @(posedge limit_div_10ms or posedge rst)
  begin // 按键计数
    if (rst)
    begin
      button_counter1 <= 0;
      button_counter0 <= 0;
    end
    else
    begin
      if (button_count)
      begin
        if (button_counter0 < 4'b1001)
        begin
          button_counter0 <= button_counter0 + 1;
        end
        else
        begin
          button_counter1 <= button_counter1 + 1;
          button_counter0 <= 0;
        end
      end
    end
  end

  always @(posedge clk or posedge rst or posedge button_dec_counter)
  begin // 十进制计数器
    if (rst||button_dec_counter)
    begin
      dec_counter1 <= 0;
      dec_counter0 <= 0;
      timer_100ms <= 0;
    end
    else
    begin
      timer_100ms <= timer_100ms + 1;
      if((dec_counter1 == 2) && (dec_counter0 == 0 ))
      begin
        timer_100ms <= 0;
      end
      if(timer_100ms >= 10000000)
            //if(timer_100ms >= 1000000)
      begin
        timer_100ms <= 0;
        if (dec_counter0 < 4'b1001)
        begin
          dec_counter0 <= dec_counter0 + 1;
        end
        else
        begin
          dec_counter1 <= dec_counter1 + 1;
          dec_counter0 <= 0;
        end

      end
    end
  end

  always@*
  begin
    case(data[p])
      4'd0:
        led_cx<=8'b00000011;
      4'd1:
        led_cx<=8'b10011111;
      4'd2:
        led_cx<=8'b00100101;
      4'd3:
        led_cx<=8'b00001101;
      4'd4:
        led_cx<=8'b10011001;
      4'd5:
        led_cx<=8'b01001001;
      4'd6:
        led_cx<=8'b01000001;
      4'd7:
        led_cx<=8'b00011111;
      4'd8:
        led_cx<=8'b00000001;
      4'd9:
        led_cx<=8'b00011001;
      default:
        led_cx<=8'b00000011;
    endcase
  end

endmodule

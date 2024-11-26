`timescale 1ns / 1ps

module flowing_water_lights_tb;
    reg clk;
    reg rst;
    reg button;
    reg [1:0] freq_set;
    reg dir_set;
    wire [7:0] led;

    flowing_water_lights uut (
        .clk(clk),
        .rst(rst),
        .button(button),
        .freq_set(freq_set),
        .dir_set(dir_set),
        .led(led)
    );

    // 时钟生成
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 100MHz 时钟
    end

    // 仿真过程
    initial begin
        // 初始化信号
        rst = 1;
        button = 0;
        freq_set = 2'b00; // 初始间隔 0.01s
        dir_set = 0; // 初始方向

        // 复位
        #10 rst = 0; 
        #10;

        // 启动
        button = 1;
        #10 button = 0;
        #10000; 

        // 暂停
        button = 1;
        #10 button = 0; 
        #10000; 
        // 继续
        button = 1; 
        #10 button = 0; 
        #10000; 
        
        // 间隔切换
        freq_set = 2'b01; 
        #10000; 

        // 方向切换
        dir_set = 1; 
        #30000;

        // 结束仿真
        $finish;
    end

endmodule
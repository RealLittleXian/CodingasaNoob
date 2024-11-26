`timescale 1ns / 1ps

module flowing_water_lights_tb;
    reg clk;
    reg rst;
    reg button;
    reg [1:0] freq_set;
    reg dir_set;
    wire [7:0] led;

    // 实例化流水灯模块
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
        dir_set = 0; // 初始方向设置为正向

        // 复位
        #10 rst = 0; // 解除复位
        #10;

        // 启动
        button = 1; // 模拟按下按钮
        #10 button = 0; // 释放按钮
        #100000; // 等待一段时间以观察 LED

        // 暂停
        button = 1; // 模拟按下按钮
        #10 button = 0; // 释放按钮
        #10000; // 等待观察
        // 继续
        button = 1; // 模拟再次按下按钮
        #10 button = 0; // 释放按钮
        #10000; // 等待观察
        
        // 间隔切换
        freq_set = 2'b01; // 切换到 0.1s
        #10000; // 等待观察

        // 方向切换
        dir_set = 1; // 切换方向
        #30000; // 等待观察

        // 结束仿真
        $finish;
    end

    // 打印 LED 状态
    always @(posedge clk) begin
        $display("LED: %b", led);
    end
endmodule
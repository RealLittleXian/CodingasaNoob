`timescale 1ns / 1ps

module reg8file_tb;

    reg clk;
    reg clr;
    reg en;
    reg [2:0] wsel;
    reg [2:0] rsel;
    reg [7:0] d;
    wire [7:0] q;

    // 实例化 reg8file 模块
    reg8file uut (
        .clk(clk),
        .clr(clr),
        .en(en),
        .wsel(wsel),
        .rsel(rsel),
        .d(d),
        .q(q)
    );

    // 时钟生成
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 每5ns翻转一次
    end

    initial begin
        // 初始化
        clr = 0;
        en = 0;
        wsel = 3'b000;
        rsel = 3'b000;
        d = 8'b0;

        // 清零
        clr = 1; 
        #10;
        clr = 0;

        // 写入数据1
        en = 1;
        d = 8'b00000011; // 第一个数据
        wsel = 3'b001; // 写入到 regfile[1]
        #10;

        // 读取数据1
        en = 0;
        rsel = 3'b001; // 读取 regfile[1]
        #10;

        // 写入数据2
        en = 1;
        d = 8'b00001100; // 第二个数据
        wsel = 3'b011; // 写入到 regfile[3]
        #10;

        // 读取数据2
        en = 0;
        rsel = 3'b011; // 读取 regfile[3]
        #10;

        // 清零
        clr = 1; 
        #10;
        clr = 0;
        // 写入数据1
        en = 1;
        d = 8'b00000011; // 第一个数据
        wsel = 3'b001; // 写入到 regfile[1]
        #10;

        // 读取数据1
        en = 0;
        rsel = 3'b001; // 读取 regfile[1]
        #10;
        // 结束仿真
        $finish;
    end

endmodule
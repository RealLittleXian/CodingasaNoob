`timescale 1ns / 1ps

module reg8file_tb;

    reg clk;
    reg clr;
    reg en;
    reg [2:0] wsel;
    reg [2:0] rsel;
    reg [7:0] d;
    wire [7:0] q;

    // ʵ���� reg8file ģ��
    reg8file uut (
        .clk(clk),
        .clr(clr),
        .en(en),
        .wsel(wsel),
        .rsel(rsel),
        .d(d),
        .q(q)
    );

    // ʱ������
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // ÿ5ns��תһ��
    end

    initial begin
        // ��ʼ��
        clr = 0;
        en = 0;
        wsel = 3'b000;
        rsel = 3'b000;
        d = 8'b0;

        // ����
        clr = 1; 
        #10;
        clr = 0;

        // д������1
        en = 1;
        d = 8'b00000011; // ��һ������
        wsel = 3'b001; // д�뵽 regfile[1]
        #10;

        // ��ȡ����1
        en = 0;
        rsel = 3'b001; // ��ȡ regfile[1]
        #10;

        // д������2
        en = 1;
        d = 8'b00001100; // �ڶ�������
        wsel = 3'b011; // д�뵽 regfile[3]
        #10;

        // ��ȡ����2
        en = 0;
        rsel = 3'b011; // ��ȡ regfile[3]
        #10;

        // ����
        clr = 1; 
        #10;
        clr = 0;
        // д������1
        en = 1;
        d = 8'b00000011; // ��һ������
        wsel = 3'b001; // д�뵽 regfile[1]
        #10;

        // ��ȡ����1
        en = 0;
        rsel = 3'b001; // ��ȡ regfile[1]
        #10;
        // ��������
        $finish;
    end

endmodule
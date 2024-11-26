`timescale 1ns / 1ps

module flowing_water_lights_tb;
    reg clk;
    reg rst;
    reg button;
    reg [1:0] freq_set;
    reg dir_set;
    wire [7:0] led;

    // ʵ������ˮ��ģ��
    flowing_water_lights uut (
        .clk(clk),
        .rst(rst),
        .button(button),
        .freq_set(freq_set),
        .dir_set(dir_set),
        .led(led)
    );

    // ʱ������
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 100MHz ʱ��
    end

    // �������
    initial begin
        // ��ʼ���ź�
        rst = 1;
        button = 0;
        freq_set = 2'b00; // ��ʼ��� 0.01s
        dir_set = 0; // ��ʼ��������Ϊ����

        // ��λ
        #10 rst = 0; // �����λ
        #10;

        // ����
        button = 1; // ģ�ⰴ�°�ť
        #10 button = 0; // �ͷŰ�ť
        #100000; // �ȴ�һ��ʱ���Թ۲� LED

        // ��ͣ
        button = 1; // ģ�ⰴ�°�ť
        #10 button = 0; // �ͷŰ�ť
        #10000; // �ȴ��۲�
        // ����
        button = 1; // ģ���ٴΰ��°�ť
        #10 button = 0; // �ͷŰ�ť
        #10000; // �ȴ��۲�
        
        // ����л�
        freq_set = 2'b01; // �л��� 0.1s
        #10000; // �ȴ��۲�

        // �����л�
        dir_set = 1; // �л�����
        #30000; // �ȴ��۲�

        // ��������
        $finish;
    end

    // ��ӡ LED ״̬
    always @(posedge clk) begin
        $display("LED: %b", led);
    end
endmodule
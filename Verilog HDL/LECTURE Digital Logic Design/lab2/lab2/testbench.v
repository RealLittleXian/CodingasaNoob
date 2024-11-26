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
        dir_set = 0; // ��ʼ����

        // ��λ
        #10 rst = 0; 
        #10;

        // ����
        button = 1;
        #10 button = 0;
        #10000; 

        // ��ͣ
        button = 1;
        #10 button = 0; 
        #10000; 
        // ����
        button = 1; 
        #10 button = 0; 
        #10000; 
        
        // ����л�
        freq_set = 2'b01; 
        #10000; 

        // �����л�
        dir_set = 1; 
        #30000;

        // ��������
        $finish;
    end

endmodule
`timescale 1ns / 1ps

module flowing_water_lights(
    input wire clk,
    input wire rst,
    input wire button,
    input wire [1:0] freq_set,
    input wire dir_set,
    output reg [7:0] led
);
    reg [31:0] counter;
    reg [3:0] current_led;
    reg running;
    reg [31:0] interval;

    // ���ؼ��Ĵ���
    reg button_reg1, button_reg2, button_reg3;
    wire button_edge;

    // ʱ����
    always @(*) begin
        case (freq_set)
            2'b00: interval = 1000000; // 0.01s
            2'b01: interval = 10000000; // 0.1s
            2'b10: interval = 25000000; // 0.25s
            2'b11: interval = 50000000; // 0.5s
            default: interval = 1000000; // Ĭ�� 0.01s
        endcase
    end

    // ���ؼ���߼�
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            button_reg1 <= 1'b0;
            button_reg2 <= 1'b0;
            button_reg3 <= 1'b0;
        end else begin
            button_reg1 <= button;
            button_reg2 <= button_reg1;
            button_reg3 <= button_reg2;
        end
    end

    assign button_edge = button_reg2 & ~button_reg3; // �����ؼ��

    // ״̬��
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            led <= 8'b00000001; // ��λֻ��LED0
            current_led <= 4'b0000; // ��ǰ����
            counter <= 32'b0; // ����������
            running <= 1'b0; // ��ֹ̬ͣ
        end else begin
            // ���ؼ��
            if (button_edge) begin
                running <= ~running; // �л�����״̬
            end

            if (running) begin
                counter <= counter + 1;
                if (counter >= interval) begin
                    counter <= 32'b0; // ���ü�����
                    // �ƶ��ƹ�
                    if (dir_set) begin
                        current_led <= (current_led - 1 + 8) % 8; // �����ƶ�
                    end else begin
                        current_led <= (current_led + 1) % 8; // �����ƶ�
                    end
                    led <= 8'b00000001 << current_led;
                end
            end
        end
    end
endmodule
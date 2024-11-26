
`timescale 1ns / 1ps

module testbench();
reg clk,rst,button_count,button_dec_counter;
reg [7:0]sw;
wire [7:0]led_en;
wire [7:0]led_cx;
led_display_ctrl uut(
    .clk(clk),
    .rst(rst),
    .led_en(led_en),
    .led_cx(led_cx),
    .button_count(button_count),
    .button_dec_counter(button_dec_counter),
    .sw(sw)
);
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 100MHz ʱ��
    end
    
initial begin
    clk=0;
    button_count=1'b0;
    button_dec_counter=1'b0;
    sw=8'b00000000;
    rst=1'b1;

    #5
    rst=1'b0;

    #5
    sw[0]=1;
    #5
    sw[1]=1;
    sw[2]=1;
    sw[3]=1;
    #5
    sw[0]=0;
    sw[1]=0;
    sw[2]=0;
    sw[3]=0;
    
    #5
    button_count=1'b1;
    #100000000
    button_count=1'b0;

    #5
    button_count=1'b1;
    #100000000
    button_count=1'b0;
    #100
    button_count=1'b1;
    #100
    button_count=1'b0;
    #100
    button_count=1'b1;
    #100
    button_count=1'b0;  // ģ�ⶶ��

    #50000000
    button_count=1'b1;
    #50000000 // ʱ����̣�������
    button_count=1'b0;

    #50000000
    rst=1'b1;
    #5
    rst=1'b0;
    #250000000 // ��λ��ֱ�Ӽ�����ʮ���Ƽ������ߵ�20
    button_dec_counter=1'b1; // �����첽����
    #10
    button_dec_counter=1'b0;
    #5
    rst=1'b1;
    #5
    rst=1'b0;
    #100000000 // ��λ��ֱ�Ӽ�����ʮ���Ƽ������ߵ�10
    #5
    rst=1'b1;
    #5
    rst=1'b0;
    #250000000 // 2s
    
    $finish;
end

endmodule

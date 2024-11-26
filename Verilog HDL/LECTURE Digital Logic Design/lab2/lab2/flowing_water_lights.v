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

    // ±ßÑØ¼ì²â¼Ä´æÆ÷
    reg button_reg1, button_reg2, button_reg3;
    wire button_edge;

    // Ê±¼ä¼ä¸ô
    always @(*) begin
        case (freq_set)
            2'b00: interval = 1000000; // 0.01s
            2'b01: interval = 10000000; // 0.1s
            2'b10: interval = 25000000; // 0.25s
            2'b11: interval = 50000000; // 0.5s
            default: interval = 1000000; // Ä¬ÈÏ 0.01s
        endcase
    end

    // ±ßÑØ¼ì²âÂß¼­
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

    assign button_edge = button_reg2 & ~button_reg3; // ÉÏÉýÑØ¼ì²â

    // ×´Ì¬»ú
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            led <= 8'b00000001; // ¸´Î»Ö»ÁÁLED0
            current_led <= 4'b0000; // µ±Ç°ÁÁµÆ
            counter <= 32'b0; // ¼ÆÊýÆ÷ÇåÁã
            running <= 1'b0; // ³õÌ¬Í£Ö¹
        end else begin
            // ±ßÑØ¼ì²â
            if (button_edge) begin
                running <= ~running; // ÇÐ»»ÔËÐÐ×´Ì¬
            end

            if (running) begin
                counter <= counter + 1;
                if (counter >= interval) begin
                    counter <= 32'b0; // ÖØÖÃ¼ÆÊýÆ÷
                    // ÒÆ¶¯µÆ¹â
                    if (dir_set) begin
                        current_led <= (current_led - 1 + 8) % 8; // Ïò×óÒÆ¶¯
                    end else begin
                        current_led <= (current_led + 1) % 8; // ÏòÓÒÒÆ¶¯
                    end
                    led <= 8'b00000001 << current_led;
                end
            end
        end
    end
endmodule
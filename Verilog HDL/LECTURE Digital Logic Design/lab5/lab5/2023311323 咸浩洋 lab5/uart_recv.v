`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/11 08:46:14
// Design Name: 
// Module Name: uart_receive
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`define bit_clk_cnt 10416
`define mid_bit_clk_cnt 5208

module uart_recv(
    input clk,
    input rst,
    input din,
    output reg valid,
    output reg[7:0] data
);

localparam IDLE  = 2'b00;
localparam START = 2'b01;
localparam DATA  = 2'b10;
localparam STOP  = 2'b11;

reg [31:0] clk_cnt;
reg [3:0] bit_pos;
reg [1:0] state;

always @(posedge clk or posedge rst) begin
    if(rst) begin
        clk_cnt <= 0;
        bit_pos <= 0;
        state <= 0;
        valid <= 0;
        data <= 0;
    end else begin
        case (state)
            IDLE: begin
                if (!din) begin
                    clk_cnt <= 0;
                    state <= START;
                end
            end
            START: begin
                if (clk_cnt == `bit_clk_cnt) begin
                    clk_cnt <= 0;
                    bit_pos <= 0;
                    state <= DATA;
                end else begin
                    clk_cnt <= clk_cnt + 1;
                end
            end
            DATA: begin
                if (clk_cnt == `mid_bit_clk_cnt) begin
                    data[bit_pos] <= din;
                end
                if (clk_cnt == `bit_clk_cnt) begin
                    clk_cnt <= 0;
                    if (bit_pos == 7) begin
                        state <= STOP;
                    end else begin
                        bit_pos <= bit_pos + 1;
                    end
                end else begin
                    clk_cnt <= clk_cnt + 1;
                end
            end
            default: begin
                if (clk_cnt == `mid_bit_clk_cnt) begin
                    valid <= 1;
                end else if (clk_cnt == `mid_bit_clk_cnt + 1) begin
                    valid <= 0;
                end
                if (clk_cnt == `bit_clk_cnt) begin
                    clk_cnt <= 0;
                    state <= IDLE;
                end else begin
                    clk_cnt <= clk_cnt + 1;
                end
            end
        endcase
    end
end

endmodule

`timescale 1ns / 1ps

module my_tb;

reg clk;
reg rst;
wire dout;

my_uart u_my_uart(
    .clk(clk),
    .rst(rst),
    .dout(dout)
);

always #5 clk = ~clk;

initial begin
    clk = 0;
    rst = 1;
    #100
    rst = 0;
    #1000000000
    $finish;
end

endmodule

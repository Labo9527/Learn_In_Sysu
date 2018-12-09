`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 10:31:28
// Design Name: 
// Module Name: KeepWire
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


module KeepWire(
    input CLK,
    input [31:0] in,
    output reg[31:0] out
    );
    initial out=0;
    always@(posedge CLK) begin
    #1;
        out=in;
    end
endmodule

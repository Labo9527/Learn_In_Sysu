`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 09:26:02
// Design Name: 
// Module Name: Multiplexer2_32
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


module Multiplexer2_32(
    input Src,
    input [31:0] input1,
    input [31:0] input2,
    output [31:0] out
    );
    assign out=(Src==0)?input1:input2;
endmodule

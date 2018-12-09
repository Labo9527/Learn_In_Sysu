`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 10:50:49
// Design Name: 
// Module Name: Multiplexer4
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


module Multiplexer4(
    input [1:0] PCSrc,
    input [31:0] in1,
    input [31:0] in2,
    input [31:0] in3,
    input [31:0] in4,
    input [31:0] out
    );
    assign out=(PCSrc==2'b00)?in1:((PCSrc==2'b01)?in2:((PCSrc==2'b10)?in3:in4));
endmodule

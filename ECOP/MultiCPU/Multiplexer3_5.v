`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 09:27:45
// Design Name: 
// Module Name: Multiplexer3_5
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


module Multiplexer3_5(
    input [1:0] Src,
    input [4:0] input1,
    input [4:0] input2,
    input [4:0] input3,
    input [4:0] out
    );
    assign out=(Src==2'b00)?input1:((Src==2'b01)?input2:input3);
endmodule

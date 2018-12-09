`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 10:04:22
// Design Name: 
// Module Name: SignZeroExtend
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


module SignZeroExtend(
    input ExtSel,
    input [15:0] in,
    input [31:0] out
    );
    assign out[15:0]=in[15:0];
    assign out[31:16]=(ExtSel==1)?(in[15]==1?16'hffff:16'h0000):16'h0000;
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 10:41:35
// Design Name: 
// Module Name: IR
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


module IR(
    input CLK,
    input IRWre,
    input [31:0] IDataOut,
    output reg[5:0] op,
    output reg[4:0] rs,
    output reg[4:0] rt,
    output reg[4:0] rd,
    output reg[4:0] sa,
    output reg[15:0] immediate
    );
    
    always@(posedge CLK) begin
    if(IRWre==1) begin
        sa[4:2] = IDataOut[10:8];
        sa[1:0]=IDataOut[7:6];
        op=IDataOut[31:26];
        rs[4:3]=IDataOut[25:24];
        rs[2:0]=IDataOut[23:21];
        rt=IDataOut[20:16];
        rd=IDataOut[15:11];
        immediate[15:8]=IDataOut[15:8];
        immediate[7:0]=IDataOut[7:0];
        end
    end
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/07 11:09:53
// Design Name: 
// Module Name: ALU
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


module ALU(
    input [31:0] inputA,
    input [31:0] inputB,
    output reg zero,
    output reg [31:0] result,
    input [2:0] ALUOp,
    output reg sign
    );
    initial
        begin
            zero=0;
            sign=0;
            result=0;
        end
    always @(ALUOp or inputA or inputB) begin
        case(ALUOp)
            3'b000:result=inputA+inputB;
            3'b001:result=inputA-inputB;
            3'b010:result=(inputB<<inputA);
            3'b011:result=inputA|inputB;
            3'b100:result=inputA&inputB;
            3'b101:result=(inputA<inputB)?1:0;
            3'b110:begin
                    if(inputA<inputB&&(inputA[31]==inputB[31])) result=1;
                    else if(inputA[31]==1&&inputB[31]==0) result=1;
                    else result=0; 
                   end
            3'b111:result=inputA^inputB;
        endcase
        zero = (result==0)?1:0;
        sign = (result[31]==0)?0:1;
    end
endmodule

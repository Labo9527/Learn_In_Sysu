`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 09:00:12
// Design Name: 
// Module Name: InstructionMemory
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


module InstructionMemory(
    input InsMemRW,
    input [31:0] PCOUT,
    output [31:0] DataOut
    );
    reg[7:0] memory [0:127];
    initial
        begin
            $readmemb("D:/test2.txt", memory);
        end
    assign DataOut[31:24]=memory[PCOUT+0][7:0];
    assign DataOut[23:16]=memory[PCOUT+1][7:0];
    assign DataOut[15:8]=memory[PCOUT+2][7:0];
    assign DataOut[7:0]=memory[PCOUT+3][7:0];
endmodule

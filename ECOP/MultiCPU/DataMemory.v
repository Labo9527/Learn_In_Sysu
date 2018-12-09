`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 09:13:58
// Design Name: 
// Module Name: DataMemory
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


module DataMemory(
    input WR,
    input RD,
    input [31:0] DAddr,
    input [31:0] DataIn,
    output reg[31:0] DataOut
    );
    reg [7:0] memory[0:127];
    integer i;
    initial
        begin
            for(i=0;i<128;i=i+1)    memory[i]<=0;
            DataOut=0;
        end
    always@(*)
        begin
        if(RD==1)
                    begin
                        DataOut[31:24]<=memory[DAddr];
                        DataOut[23:16]<=memory[DAddr+1];
                        DataOut[15:8]<=memory[DAddr+2];
                        DataOut[7:0]<=memory[DAddr+3];
                    end
        else if(WR==1)
                begin
                    memory[DAddr]<=DataIn[31:24];
                    memory[DAddr+1]<=DataIn[23:16];
                    memory[DAddr+2]<=DataIn[15:8];
                    memory[DAddr+3]<=DataIn[7:0];
                end
            
        end    
    
endmodule

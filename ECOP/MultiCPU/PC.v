`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/07 13:16:01
// Design Name: 
// Module Name: PC
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


module PC(
    input CLK,
    input RST,
    input PCWre,
    input [31:0] PCIN,
    output reg[31:0] PCOUT
    );
    initial begin
        PCOUT<=0;
    end
    always@(posedge CLK or posedge RST) begin
        if(RST==1)    PCOUT<=0;
        else begin
            if(PCWre==1)    PCOUT<=PCIN;
            end
        end
    
endmodule

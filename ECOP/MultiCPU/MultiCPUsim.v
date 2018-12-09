`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 19:44:24
// Design Name: 
// Module Name: MultiCPUsim
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


module MultiCPUsim();
    reg CLK;
    reg Reset;
    wire [31:0]PCIN;
    wire [31:0]PCOUT;
    wire zero;
    wire sign;
    wire [5:0]opcode;
    wire WrRegDSrc;
    wire [1:0]RegDst;
    wire RegWre;
    wire [2:0] ALUOp;
    wire [1:0] PCSrc;
    wire ALUSrcA;
    wire ALUSrcB;
    wire mRD;
    wire mWR;
    wire DBDataSrc;
    wire PCWre;
    wire ExtSel;
    wire InsMemRW;
    wire IRWre;
    wire [31:0]DataOut;
    wire [31:0]ReadData1;
    wire [31:0]ReadData2;
    wire [31:0]result;
    wire [4:0] rs;
    wire [4:0] rt;
    wire [4:0] rd;
    wire [4:0] sa;
    wire [15:0] immediate;
    wire [4:0] WriteReg;
    wire [31:0] WriteData;
    wire [31:0] PC4;
    wire [31:0] IDataOut;
    wire [2:0] State;
    wire [31:0]inputA;
    wire [31:0]inputB;
    wire [31:0]ADR;
    wire [31:0]BDR;
    wire [31:0]DB;
    wire [31:0]DAddr;

    MultiCPU mcpu(.CLK(CLK),
    .Reset(Reset),
    .PCIN(PCIN),
    .PCOUT(PCOUT),
    .zero(zero),
    .sign(sign),
    .opcode(opcode),
    .WrRegDSrc(WrRegDSrc),
    .RegDst(RegDst),
    .RegWre(RegWre),
    .ALUOp(ALUOp),
    .PCSrc(PCSrc),
    .ALUSrcA(ALUSrcA),
    .ALUSrcB(ALUSrcB),
    .mRD(mRD),
    .mWR(mWR),
    .DBDataSrc(DBDataSrc),
    .PCWre(PCWre),
    .ExtSel(ExtSel),
    .InsMemRW(InsMemRW),
    .IRWre(IRWre),
    .DataOut(DataOut),
    .ReadData1(ReadData1),
    .ReadData2(ReadData2),
    .result(result),
    .rs(rs),
    .rt(rt),
    .rd(rd),
    .sa(sa),
    .immediate(immediate),
    .WriteReg(WriteReg),
    .WriteData(WriteData),
    .PC4(PC4),
    .IDataOut(IDataOut),
    .State(State),
    .inputA(inputA),
    .inputB(inputB),
    .ADR(ADR),
    .BDR(BDR),
    .DB(DB),
    .DAddr(DAddr));
    
    always #10 CLK=~CLK;
    initial begin
        CLK=0;
        Reset=1;
        #5 Reset=0;
    end

endmodule

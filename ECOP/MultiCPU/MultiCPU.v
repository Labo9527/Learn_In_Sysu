`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 18:44:27
// Design Name: 
// Module Name: MultiCPU
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


module MultiCPU(
    input CLK,
    input Reset,
    output [31:0]PCIN,
    output [31:0]PCOUT,
    output zero,
    output sign,
    output [5:0]opcode,
    output WrRegDSrc,
    output [1:0]RegDst,
    output RegWre,
    output [2:0] ALUOp,
    output [1:0] PCSrc,
    output ALUSrcA,
    output ALUSrcB,
    output mRD,
    output mWR,
    output DBDataSrc,
    output PCWre,
    output ExtSel,
    output InsMemRW,
    output IRWre,
    output [31:0]DataOut,
    output [31:0]ReadData1,
    output [31:0]ReadData2,
    output [31:0]result,
    output [4:0] rs,
    output [4:0] rt,
    output [4:0] rd,
    output [4:0] sa,
    output [15:0] immediate,
    output [4:0] WriteReg,
    output [31:0] WriteData,
    output [31:0] PC4,
    output [31:0] IDataOut,
    output [2:0] State,
    output [31:0]inputA,
    output [31:0]inputB,
    output [31:0]ADR,
    output [31:0]BDR,
    output [31:0]DB,
    output [31:0]DAddr
    );
    //wire inputA,inputB;
    //wire [31:0]DBDataSrc;
    //wire [31:0] IDataOut;
    //wire [31:0]DB;
    
    wire[31:0] extendImmediate;
    
    wire [4:0] ThreeOne;
    
    wire [31:0] DBDR;
    
    assign ThreeOne=5'b11111;
    
    //wire [31:0] PC4;
    wire [31:0] PC3;
    wire [31:0] PC1;
    wire [31:0] truesa;
    assign PC4=PCOUT+4;
    assign PC3={PCOUT[31:28],IDataOut[25:0],2'b00};
    assign PC1=PC4+(extendImmediate<<2);
    assign truesa={{27{1'b0}},sa};
    
    
    SignZeroExtend sg(ExtSel,immediate,extendImmediate);
    
    PC pc(CLK,Reset,PCWre,PCIN,PCOUT);
    
    ControlUnit cu(CLK,Reset,zero,sign,opcode,WrRegDSrc,
    RegDst,RegWre,ALUOp,PCSrc,ALUSrcA,ALUSrcB,mRD,mWR,
    DBDataSrc,PCWre,ExtSel,InsMemRW,IRWre,State);
    
    InstructionMemory im(InsMemRW,PCOUT,IDataOut);
    
    Multiplexer2_32 mul2_32_2(WrRegDSrc,PC4,DB,WriteData);
    
    Multiplexer3_5 mul3(RegDst,ThreeOne,rt,rd,WriteReg);
    
    Multiplexer2_32 mul_2_32_1(DBDataSrc,result,DataOut,DBDR);
    
    Multiplexer4 mul4(PCSrc,PC4,PC1,ReadData1,PC3,PCIN);
    
    //wire [31:0]ADR;
    //wire [31:0]BDR;
    
    KeepWire kw1(CLK,ReadData1,ADR);
    KeepWire kw2(CLK,ReadData2,BDR);
    KeepWire kw3(CLK,result,DAddr);
    KeepWire kw4(CLK,DBDR,DB);
    
    Multiplexer2_32 mul_2_32_5(ALUSrcA,ADR,truesa,inputA);
    Multiplexer2_32 mul_2_32_6(ALUSrcB,BDR,extendImmediate,inputB);
    
    ALU alu(inputA,inputB,zero,result,ALUOp,sign);
    
    DataMemory dm(mWR,mRD,DAddr,BDR,DataOut);
    
    IR ir(CLK,IRWre,IDataOut,opcode,rs,rt,
    rd,sa,immediate);
    
    RegFile rf(CLK,RegWre,rs,rt,WriteReg,WriteData,
    ReadData1,ReadData2);
    
endmodule

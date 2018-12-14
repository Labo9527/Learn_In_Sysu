module RegFile(
    input CLK,
    input RegWre,
    input [4:0] ReadReg1,
    input [4:0] ReadReg2,
    input [4:0] WriteReg,
    input [31:0] WriteData,
    output reg [31:0] ReadData1,
    output reg [31:0] ReadData2
    );
    reg [31:0] regFile[1:31];
    integer i;
    initial
        begin
            for(i=1;i<32;i=i+1) regFile[i]<=0;
        end
    always @(posedge CLK or negedge CLK) begin
     ReadData1<=(ReadReg1==0)?0:regFile[ReadReg1];
     ReadData2<=(ReadReg2==0)?0:regFile[ReadReg2];
    end
    always @(*) begin
        if(RegWre==1&&WriteReg!=0)
        begin
            regFile[WriteReg]=WriteData;
        end
    end
endmodule
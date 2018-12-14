module ControlUnit(
    input CLK,
    input Reset,
    input zero,
    input sign,
    input [5:0] opcode,
    output reg WrRegDSrc,
    output reg[1:0] RegDst,
    output reg RegWre,
    output reg[2:0] ALUOp,
    output reg[1:0] PCSrc,
    output reg ALUSrcA,
    output reg ALUSrcB,
    output reg mRD,
    output reg mWR,
    output reg DBDATASrc,
    output reg PCWre,
    output reg ExtSel,
    output reg InsMemRW,
    output reg IRWre,
    output reg[2:0] State
    );
    //reg[2:0] State;
    always@(negedge CLK) begin
        if(opcode==6'b111111) begin PCWre=0; end
    end
    always@(opcode or sign or zero)begin
        if(opcode==6'b110101)
                    begin
                       ALUSrcA=0;
                       ALUSrcB=0;
                       InsMemRW=1;
                                       DBDATASrc=0;
                       ALUOp=3'b001;
                       if(zero==1) PCSrc=0;
                       else PCSrc=1;
                       ExtSel=1;
                       RegDst=2'b01;
                       WrRegDSrc=1; 
                    end
    end
    
    always@(negedge CLK or posedge Reset) begin
        if(Reset==1)
            begin
                State=3'b000;
                WrRegDSrc=1;
                RegDst=2'b00;
                RegWre=0;
                ALUOp=3'b000;
                PCSrc=2'b00;
                ALUSrcA=0;
                ALUSrcB=0;
                mRD=0;
                mWR=0;
                DBDATASrc=0;
                PCWre=0;
                ExtSel=0;
                InsMemRW=1;
                IRWre=1;
            end
        else
            begin
                case(State)
                    3'b000:
                        begin
                        if(opcode==6'b111111)
                            begin
                                State<=3'b000;
                                PCWre=0;
                            end
                        else
                            begin    
                            State<=3'b001;
                            //WrRegDSrc=1;
                            if(opcode==6'b111010)
                              begin RegWre=0; end
                              else begin RegWre=0; end
                            RegWre=(opcode==6'b111010)?0:0;
                            mRD=0;
                            mWR=0;
                            PCWre=0;
                            IRWre=1;
                            end
                        end
                    3'b001:
                        begin
                            case(opcode)
                                6'b110100,6'b110101,6'b110110:begin State<=3'b101; PCWre=0; end
                                6'b110000,6'b110001:begin State<=3'b010; PCWre=0; end
                                6'b111000,6'b111001,6'b111010,6'b111111:
                                begin
                                    State<=3'b000;
                                    if(opcode==6'b111111) begin PCWre=0; end
                                    else begin PCWre=1; end
                                end
                                default:begin State<=3'b110; PCWre=0; end
                            endcase
                            //WrRegDSrc=1;
                            if(opcode==6'b111010)
                                RegWre=0;
                            else RegWre=0;
                            mRD=0;
                            mWR=0;
                            IRWre=0;
                        end
                    3'b010:
                        begin
                            State<=3'b011;
                            //WrRegDSrc=1;
                            RegWre=0;
                            if(opcode==6'b110000) mWR=1;
                            mRD=0;
                            PCWre=0;
                            IRWre=0;
                        end
                    3'b011:
                        begin
                        if(opcode==6'b110000)
                           begin State<=3'b000; mWR=0; mRD=0; PCWre=1; end
                        else begin State<=3'b100; mWR=0; mRD=1; RegWre=1; PCWre=0; end
                            //WrRegDSrc=1;
                            //RegWre=0;
                            //PCWre=1;
                            IRWre=0;
                        end
                    3'b100:
                        begin
                            State<=3'b000;
                            //WrRegDSrc=1;
                            RegWre=0;
                            mRD=0;
                            mWR=0;
                            PCWre=1;
                            IRWre=0;
                        end
                    3'b101:
                        begin
                            State<=3'b000;
                            //WrRegDSrc=1;
                            RegWre=0;
                            mRD=0;
                            mWR=0;
                            PCWre=1;
                            IRWre=0;
                        end
                    3'b110:
                        begin
                            State<=3'b111;
                            //WrRegDSrc=1;
                            RegWre=1;
                            mRD=0;
                            mWR=0;
                            PCWre=0;
                            IRWre=0;
                        end
                    3'b111:
                    begin
                        State<=3'b000;
                        //WrRegDSrc=1;
                        RegWre=0;
                        mRD=0;
                        mWR=0;
                        PCWre=1;
                        IRWre=0;
                    end
                endcase
            end
    end
    always@(opcode or sign ) begin
        case(opcode)
            6'b000000:
                begin
                    ALUSrcA=0;
                    ALUSrcB=0;
                    InsMemRW=1;
                    DBDATASrc=0;
                    ALUOp=3'b000;
                    PCSrc=0;
                    ExtSel=0;
                    RegDst=2'b10;
                    WrRegDSrc=1;
                end
            6'b000001:
               begin
                    ALUSrcA=0;
                    ALUSrcB=0;
                    InsMemRW=1;
                    DBDATASrc=0;
                    ALUOp=3'b001;
                    PCSrc=0;
                    ExtSel=0;
                    RegDst=2'b10;
                    WrRegDSrc=1;
               end
           6'b000010:
                begin
                    ALUSrcA=0;
                    ALUSrcB=1;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b000;
                    PCSrc=0;
                    ExtSel=1;
                    RegDst=2'b01;
                    WrRegDSrc=1;
                end
          6'b010000:
                begin
                    ALUSrcA=0;
                    ALUSrcB=0;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b100;
                    PCSrc=0;
                    ExtSel=0;
                    RegDst=2'b10;
                    WrRegDSrc=1;
                end
         6'b010001:
                begin
                    ALUSrcA=0;
                    ALUSrcB=1;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b100;
                    PCSrc=0;
                    ExtSel=0;
                    RegDst=2'b01;
                    WrRegDSrc=1;
                end
         6'b010010:
                begin
                    ALUSrcA=0;
                    ALUSrcB=1;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b011;
                    PCSrc=0;
                    ExtSel=0;
                    RegDst=2'b01;
                    WrRegDSrc=1;
                end
         6'b010011:
                begin
                    ALUSrcA=0;
                    ALUSrcB=1;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b111;
                    PCSrc=0;
                    ExtSel=0;
                    RegDst=2'b01;
                    WrRegDSrc=1;
                end
         6'b011000:
                begin
                    ALUSrcA=1;
                    ALUSrcB=0;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b010;
                    PCSrc=0;
                    ExtSel=0;
                    RegDst=2'b10;
                    WrRegDSrc=1;
                end
         6'b100110:
                begin
                    ALUSrcA=0;
                    ALUSrcB=1;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b110;
                    PCSrc=0;
                    ExtSel=1;
                    RegDst=2'b01;
                    WrRegDSrc=1;
                end
         6'b100111:
                begin
                    ALUSrcA=0;
                    ALUSrcB=0;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b110;
                    PCSrc=0;
                    ExtSel=1;
                    RegDst=2'b10;
                    WrRegDSrc=1;
                end
         6'b110000:
                begin
                    ALUSrcA=0;
                    ALUSrcB=1;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b000;
                    PCSrc=0;
                    ExtSel=1;
                    RegDst=2'b01;
                    WrRegDSrc=1;
                end
         6'b110001:
                begin
                    ALUSrcA=0;
                    ALUSrcB=1;
                    InsMemRW=1;
                                    DBDATASrc=1;
                    ALUOp=3'b000;
                    PCSrc=0;
                    ExtSel=1;
                    RegDst=2'b01;
                    WrRegDSrc=1;
                end
         6'b110100:
                begin
                    ALUSrcA=0;
                    ALUSrcB=0;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b001;
                    if(zero!=1) PCSrc=0;
                    else PCSrc=1;
                    ExtSel=1;
                    RegDst=2'b01;
                    WrRegDSrc=1;
                end
         6'b110101:
                begin
                   ALUSrcA=0;
                   ALUSrcB=0;
                   InsMemRW=1;
                                   DBDATASrc=0;
                   ALUOp=3'b001;
                   if(zero==1) PCSrc=0;
                   else PCSrc=1;
                   ExtSel=1;
                   RegDst=2'b01;
                   WrRegDSrc=1; 
                end
         6'b110110:
                begin
                    ALUSrcA=0;
                    ALUSrcB=0;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b001;
                    if(sign!=1) PCSrc=0;
                    else PCSrc=1;
                    ExtSel=1;
                    RegDst=2'b00;
                    WrRegDSrc=1;
                end
         6'b111000:
                begin
                    ALUSrcA=0;
                    ALUSrcB=0;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b000;
                    PCSrc=2'b11;
                    ExtSel=1;
                    RegDst=2'b00;
                    WrRegDSrc=1;
                end
         6'b111001:
                begin
                    ALUSrcA=0;
                    ALUSrcB=0;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b000;
                    PCSrc=2'b10;
                    ExtSel=1;
                    RegDst=2'b00;
                    WrRegDSrc=1;
                end
          6'b111010:
                begin
                    ALUSrcA=0;
                    ALUSrcB=0;
                    InsMemRW=1;
                                    DBDATASrc=0;
                    ALUOp=3'b000;
                    PCSrc=2'b11;
                    ExtSel=1;
                    RegDst=2'b00;
                    WrRegDSrc=0;
                    //
                    RegWre=1;
                    //PCWre=1;
                    //
                end
         6'b111111:
                begin
                    ALUSrcA=0;
                    ALUSrcB=0;
                    InsMemRW=0;
                                    DBDATASrc=0;
                    ALUOp=3'b000;
                    PCSrc=2'b00;
                    ExtSel=0;
                    RegDst=2'b00;
                    WrRegDSrc=0;
                    PCWre=0;
                end
        endcase
    end
    
endmodule
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.*;

public class Board extends JPanel implements MouseListener {
    private static Image BoardImg;
    private static Chess[][] Chesses;
    private int Initial_X=10;
    private int Initial_Y=10;
    private int ChessSize=15;
    private int Between=30;
    protected boolean End=false;
    Board(){
        Chesses=new Chess[15][15];
        BoardImg=Toolkit.getDefaultToolkit().getImage("F:\\java_project\\Five1\\Img\\Board.png");
        //System.out.println(BoardImg);
        if(BoardImg==null)
            System.err.println("No Img Found!");
        //setPreferredSize(new Dimension(600,485));
        addMouseListener(this);
        System.out.println(this);
    }

    protected void Restart(){
        Chesses=new Chess[15][15];
        End=false;
        repaint();
    }

    @Override
    protected void paintComponent(Graphics g){
        int imgWidth=BoardImg.getWidth(this);
        int imgHeight=BoardImg.getHeight(this);
        g.drawImage(BoardImg,1,1,null);

        float[] fractions = new float[]{0,1};
        Color[] colors_b = new Color[]{Color.BLACK,Color.WHITE};
        Color[] colors_w=new Color[]{Color.WHITE,Color.BLACK};


        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                if(Chesses[i][j]!=null) {
                    //System.out.println("yes");
                    if(Chesses[i][j].getType()=='W') {
                        RadialGradientPaint paint = new RadialGradientPaint(Initial_X + i * Between, Initial_Y + j * Between, 40f, fractions, colors_w);
                        ((Graphics2D) g).setPaint(paint);
                        ((Graphics2D) g).fillOval(Initial_X + i * Between, Initial_Y + j * Between, ChessSize, ChessSize);
                    }
                    else if(Chesses[i][j].getType()=='B'){
                        RadialGradientPaint paint = new RadialGradientPaint(Initial_X + i * Between, Initial_Y + j * Between, 40f, fractions, colors_b);
                        ((Graphics2D) g).setPaint(paint);
                        ((Graphics2D) g).fillOval(Initial_X + i * Between, Initial_Y + j * Between, ChessSize, ChessSize);
                    }
                }
            }
        }


    }

    int ABS(int a){
        if(a>=0)
            return a;
        return -a;
    }

    protected boolean Down(int x,int y){
        if(x>10)
            return false;
        if(Chesses[x+1][y]==null||Chesses[x+2][y]==null||Chesses[x+3][y]==null||Chesses[x+4][y]==null)
            return false;
        char Type=Chesses[x][y].getType();
        if(Chesses[x+1][y].getType()!=Type)
            return false;
        if(Chesses[x+2][y].getType()!=Type)
            return false;
        if(Chesses[x+3][y].getType()!=Type)
            return false;
        if(Chesses[x+4][y].getType()!=Type)
            return false;
        return true;
    }

    protected boolean Top(int x,int y){
        if(x<4)
            return false;
        if(Chesses[x-1][y]==null||Chesses[x-2][y]==null||Chesses[x-3][y]==null||Chesses[x-4][y]==null)
            return false;
        char Type=Chesses[x][y].getType();
        if(Chesses[x-1][y].getType()!=Type)
            return false;
        if(Chesses[x-2][y].getType()!=Type)
            return false;
        if(Chesses[x-3][y].getType()!=Type)
            return false;
        if(Chesses[x-4][y].getType()!=Type)
            return false;
        return true;
    }

    protected boolean Right(int x,int y){
        if(y>10)
            return false;
        if(Chesses[x][y+1]==null||Chesses[x][y+2]==null||Chesses[x][y+3]==null||Chesses[x][y+4]==null)
            return false;
        char Type=Chesses[x][y].getType();
        if(Chesses[x][y+1].getType()!=Type)
            return false;
        if(Chesses[x][y+2].getType()!=Type)
            return false;
        if(Chesses[x][y+3].getType()!=Type)
            return false;
        if(Chesses[x][y+4].getType()!=Type)
            return false;
        return true;
    }

    protected boolean Left(int x,int y){
        if(y<4)
            return false;
        if(Chesses[x][y-1]==null||Chesses[x][y-2]==null||Chesses[x][y-3]==null||Chesses[x][y-4]==null)
            return false;
        char Type=Chesses[x][y].getType();
        if(Chesses[x][y-1].getType()!=Type)
            return false;
        if(Chesses[x][y-2].getType()!=Type)
            return false;
        if(Chesses[x][y-3].getType()!=Type)
            return false;
        if(Chesses[x][y-4].getType()!=Type)
            return false;
        return true;
    }

    protected boolean RightTop(int x,int y){
        if(x<4||y>10)
            return false;
        if(Chesses[x-1][y+1]==null||Chesses[x-2][y+2]==null||Chesses[x-3][y+3]==null||Chesses[x-4][y+4]==null)
            return false;
        char Type=Chesses[x][y].getType();
        if(Chesses[x-1][y+1].getType()!=Type)
            return false;
        if(Chesses[x-2][y+2].getType()!=Type)
            return false;
        if(Chesses[x-3][y+3].getType()!=Type)
            return false;
        if(Chesses[x-4][y+4].getType()!=Type)
            return false;
        return true;
    }

    protected boolean LeftTop(int x,int y){
        if(x<4||y<4)
            return false;
        if(Chesses[x-1][y-1]==null||Chesses[x-2][y-2]==null||Chesses[x-3][y-3]==null||Chesses[x-4][y-4]==null)
            return false;
        char Type=Chesses[x][y].getType();
        if(Chesses[x-1][y-1].getType()!=Type)
            return false;
        if(Chesses[x-2][y-2].getType()!=Type)
            return false;
        if(Chesses[x-3][y-3].getType()!=Type)
            return false;
        if(Chesses[x-4][y-4].getType()!=Type)
            return false;
        return true;
    }

    protected boolean RightDown(int x,int y){
        if(x>10||y>10)
            return false;
        if(Chesses[x+1][y+1]==null||Chesses[x+2][y+2]==null||Chesses[x+3][y+3]==null||Chesses[x+4][y+4]==null)
            return false;
        char Type=Chesses[x][y].getType();
        if(Chesses[x+1][y+1].getType()!=Type)
            return false;
        if(Chesses[x+2][y+2].getType()!=Type)
            return false;
        if(Chesses[x+3][y+3].getType()!=Type)
            return false;
        if(Chesses[x+4][y+4].getType()!=Type)
            return false;
        return true;
    }

    protected boolean LeftDown(int x,int y){
        if(x>10||y<4)
            return false;
        if(Chesses[x+1][y-1]==null||Chesses[x+2][y-2]==null||Chesses[x+3][y-3]==null||Chesses[x+4][y-4]==null)
            return false;
        char Type=Chesses[x][y].getType();
        if(Chesses[x+1][y-1].getType()!=Type)
            return false;
        if(Chesses[x+2][y-2].getType()!=Type)
            return false;
        if(Chesses[x+3][y-3].getType()!=Type)
            return false;
        if(Chesses[x+4][y-4].getType()!=Type)
            return false;
        return true;
    }

    protected boolean isEnd(){
        boolean Res=false;
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                if(Chesses[i][j]!=null) {
                    if (Right(i, j) || Left(i, j) || Down(i, j) || Top(i, j) || RightDown(i, j) || RightTop(i, j) || LeftDown(i, j) || LeftTop(i, j)) {
                        Res = true;
                        break;
                    }
                }
            }
            if(Res)
                break;
        }
        return Res;
    }

    private int ScoreForTuple(int x,int y,int direction){
        int Res=0;
        char Type;
        if(direction==0){
            if(Chesses[x][y]!=null)
                Type=Chesses[x][y].getType();
            else{
                Type='X';
            }
            for(int i=1;i<5;i++){
                if(Chesses[x+i][y]==null){
                    if(i==4&&Type=='X')
                        return 7;
                    continue;
                }
                else if(Type=='X'){
                    Type=Chesses[x+i][y].getType();
                    if(Type=='B')
                        Res=35;
                    else
                        Res=15;
                }
                else if(Chesses[x+i][y].getType()!=Type)
                    return 0;
                else{
                    if(Type=='B'){
                       if(Res==35)
                           Res=800;
                       else if(Res==800)
                           Res=15000;
                       else if(Res==15000)
                           Res=800000;
                    }
                    else if(Type=='W'){
                        if(Res==15)
                            Res=400;
                        else if(Res==400)
                            Res=1800;
                        else if(Res==1800)
                            Res=100000;
                    }
                }
            }
            return Res;
        }
        else if(direction==1){
            if(Chesses[x][y]!=null) {
                Type = Chesses[x][y].getType();
            }
            else{
                Type='X';
            }
            for(int i=1;i<5;i++){
                if(Chesses[x][y+i]==null){
                    if(i==4)
                        return 7;
                    continue;
                }
                else if(Type=='X'){
                    Type=Chesses[x][y+i].getType();
                    if(Type=='B')
                        Res=35;
                    else
                        Res=15;
                }
                else if(Chesses[x][y+i].getType()!=Type)
                    return 0;
                else{
                    if(Type=='B'){
                        if(Res==35)
                            Res=800;
                        else if(Res==800)
                            Res=15000;
                        else if(Res==15000)
                            Res=800000;
                    }
                    else if(Type=='W'){
                        if(Res==15)
                            Res=400;
                        else if(Res==400)
                            Res=1800;
                        else if(Res==1800)
                            Res=100000;
                    }
                }
            }
            return Res;
        }
        else if(direction==2){
            if(Chesses[x][y]!=null) {
                Type = Chesses[x][y].getType();
            }
            else{
                Type='X';
            }
            for(int i=1;i<5;i++){
                if(Chesses[x+i][y+i]==null){
                    if(i==4)
                        return 7;
                    continue;
                }
                else if(Type=='X'){
                    Type=Chesses[x+i][y+i].getType();
                    if(Type=='B')
                        Res=35;
                    else
                        Res=15;
                }
                else if(Chesses[x+i][y+i].getType()!=Type)
                    return 0;
                else{
                    if(Type=='B'){
                        if(Res==35)
                            Res=800;
                        else if(Res==800)
                            Res=15000;
                        else if(Res==15000)
                            Res=800000;
                    }
                    else if(Type=='W'){
                        if(Res==15)
                            Res=400;
                        else if(Res==400)
                            Res=1800;
                        else if(Res==1800)
                            Res=100000;
                    }
                }
            }
            return Res;
        }
        else if(direction==3){
            if(Chesses[x][y]!=null)
                Type=Chesses[x][y].getType();
            else{
                Type='X';
            }
            for(int i=1;i<5;i++){
                if(Chesses[x+i][y-i]==null){
                    if(i==4)
                        return 7;
                    continue;
                }
                else if(Type=='X'){
                    Type=Chesses[x+i][y-i].getType();
                    if(Type=='B')
                        Res=35;
                    else
                        Res=15;
                }
                else if(Chesses[x+i][y-i].getType()!=Type)
                    return 0;
                else{
                    if(Type=='B'){
                        if(Res==35)
                            Res=800;
                        else if(Res==800)
                            Res=15000;
                        else if(Res==15000)
                            Res=800000;
                    }
                    else if(Type=='W'){
                        if(Res==15)
                            Res=400;
                        else if(Res==400)
                            Res=1800;
                        else if(Res==1800)
                            Res=100000;
                    }
                }
            }
            return Res;
        }
        return 0;
    }

    private int Evalute(int x,int y){
        int Res=0;
        if(x>=4){
            Res=Res+ScoreForTuple(x-4,y,0);
        }
        if(x>=3&&x<14){
            Res=Res+ScoreForTuple(x-3,y,0);
        }
        if(x>=2&&x<13){
            Res=Res+ScoreForTuple(x-2,y,0);
        }
        if(x>=1&&x<12){
            Res=Res+ScoreForTuple(x-1,y,0);
        }
        if(x<11){
            Res=Res+ScoreForTuple(x,y,0);
        }
        if(y>=4){
            Res=Res+ScoreForTuple(x,y-4,1);
        }
        if(y>=3&&y<14){
            Res=Res+ScoreForTuple(x,y-3,1);
        }
        if(y>=2&&y<13){
            Res=Res+ScoreForTuple(x,y-2,1);
        }
        if(y>=1&&y<12){
            Res=Res+ScoreForTuple(x,y-1,1);
        }
        if(y<11){
            Res=Res+ScoreForTuple(x,y,1);
        }
        if(x>=4&&y>=4){
            Res=Res+ScoreForTuple(x-4,y-4,2);
        }
        if(x>=3&&y>=3&&x<14&&y<14){
            Res=Res+ScoreForTuple(x-3,y-3,2);
        }
        if(x>=2&&y>=2&&x<13&&y<13){
            Res=Res+ScoreForTuple(x-2,y-2,2);
        }
        if(x>=1&&y>=1&&x<12&&y<12){
            Res=Res+ScoreForTuple(x-1,y-1,2);
        }
        if(x<11&&y<11){
            Res=Res+ScoreForTuple(x,y,2);
        }
        if(x>=4&&y<11){
            Res=Res+ScoreForTuple(x-4,y+4,3);
        }
        if(x>=3&&x<14&&y>=1&&y<12){
            Res=Res+ScoreForTuple(x-3,y+3,3);
        }
        if(x>=2&&x<13&&y>=2&&y<13){
            Res=Res+ScoreForTuple(x-2,y+2,3);
        }
        if(x>=1&&x<12&&y>=3&&y<14){
            Res=Res+ScoreForTuple(x-1,y+1,3);
        }
        if(x<11&&y>=4){
            Res=Res+ScoreForTuple(x,y,3);
        }
        return Res;
    }

    private void AI(int x,int y){  //用的是比较简单的评分表法
        int[][] Score=new int[15][15];
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                if(Chesses[i][j]!=null) {
                    Score[i][j] = 0;
                    continue;
                }
                else if((ABS(i-x)!=ABS(j-y)&&i!=x&&j!=y)||ABS(i-x)>5||ABS(j-y)>5){
                    Score[i][j]=0;
                    continue;
                }
                else{
                    Score[i][j]=Evalute(i,j);
                }
            }
        }
        int MAXSCORE=0;
        int MAX_X=0,MAX_Y=0;
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                if(Score[i][j]>MAXSCORE){
                    MAX_X=i;
                    MAX_Y=j;
                    MAXSCORE=Score[i][j];
                }
            }
        }

        Chesses[MAX_X][MAX_Y]=new Chess('B');
        repaint();
    }

    @Override
    public void mousePressed(MouseEvent e){
        //System.out.println("Hello World!");
        int X=e.getX();
        int Y=e.getY();
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                int ChessX=Initial_X + i * Between;
                int ChessY=Initial_Y + j * Between;
                //System.out.println(ChessX);
                //System.out.println(ChessY);
                if(ABS(X-ChessX)<=10&&(ABS(Y-ChessY))<=10) {
                    System.out.println("Succeed!");
                    Chesses[i][j] = new Chess('W');
                    System.out.println(Chesses[i][j]);
                    repaint();
                    if(isEnd()) {
                        End=true;
                        JOptionPane.showMessageDialog(null, "游戏结束");
                    }

                    if(!End){
                        AI(i,j);
                    }

                    if(isEnd()) {
                        End=true;
                        JOptionPane.showMessageDialog(null, "游戏结束");
                    }
                }
            }
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        //System.out.println("Hello World!");
    }
    @Override
    public void mouseReleased(MouseEvent e) {
        //System.out.println("Hello World!");
    }
    @Override
    public void mouseEntered(MouseEvent e) {
        //System.out.println("Hello World!");
    }
    @Override
    public void mouseExited(MouseEvent e) {
        //System.out.println("Hello World!");
    }

}

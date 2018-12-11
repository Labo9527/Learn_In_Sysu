package Exercise3_4;

public class MovablePoint implements Movable {
    protected int x,y,xSpeed,ySpeed;

    public MovablePoint(int x,int y,int xSpeed,int ySpeed){
        this.x=x;
        this.y=y;
        this.xSpeed=xSpeed;
        this.ySpeed=ySpeed;
    }

    @Override
    public void moveUp(){
        y-=ySpeed;
    }

    @Override
    public void moveDown(){
        y+=ySpeed;
    }

    @Override
    public void moveRight(){
        x+=xSpeed;
    }

    @Override
    public void moveLeft(){
        x-=xSpeed;
    }

    @Override
    public String toString() {
        return "x:"+x+"  y:"+y+"   xSpeed:"+xSpeed+"    ySpeed"+ySpeed;
    }
}

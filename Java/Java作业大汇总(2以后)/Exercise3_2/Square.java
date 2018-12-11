package Exercise3_2;

public class Square extends Rectangle {
    private double side;
    public Square(double side){
        super(side,side);
    }
    Square(double side1,double side2){
        super(side1,side1);
    }
    Square(){
        super();
        this.side=side;
    }
    public String toString(){
        String Res="A Square with side="+side+", which is a subclass of "+super.toString();
        return Res;
    }
    double getSide() {
        return side;
    }
}
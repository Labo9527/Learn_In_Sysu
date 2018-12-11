package Exercise3_1;

public class Square extends Rectangle {
    private double side;
    public Square(double side){
        super(side,side);
    }
    Square(){
        super();
        this.side=side;
    }
    public String toString(){
        String Res="A Square with side="+side+", which is a subclass of "+super.toString();
        return Res;
    }
    double getSide(){
        return side;
    }
    public static void main(String[] args){
        Shape s1=new Square();
        Shape s2=new Square(3);
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(((Square) s1).getArea());
        System.out.println(((Square) s2).getPerimeter());
    }
}

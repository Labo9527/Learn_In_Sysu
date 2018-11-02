public class Square extends Rectangle {
    public Square(double side){
        super(side,side);
    }
    Square(){
        super();
    }
    public String toString(){
        String Res="A Square with side="+super.getWidth()+", which is a subclass of "+super.toString();
        return Res;
    }
}

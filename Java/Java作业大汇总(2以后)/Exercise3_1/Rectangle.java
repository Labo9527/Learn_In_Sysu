package Exercise3_1;

public class Rectangle extends Shape {
    private double width;
    private double length;
    Rectangle(){
        super();
        this.width=1.0;
        this.length=1.0;
    }
    Rectangle(double width,double length){
        super();
        this.width=width;
        this.length=length;
    }
    Rectangle(double width,double length,String color,boolean filled){
        super(color,filled);
        this.width=width;
        this.length=length;
    }
    double getWidth(){
        return width;
    }
    double getLength(){
        return length;
    }
    void setWidth(double width){
        this.width=width;
    }
    void setLength(double length){
        this.length=length;
    }
    double getArea(){
        return width*length;
    }
    double getPerimeter(){
        return 2*(width+length);
    }
    public String toString(){
        String Res="A Rectangle with width="+width+" and length="+length+", which is a subclass of "+super.toString();
        return Res;
    }
    public static void main(String[] args){
        Shape s1=new Rectangle();
        Shape s2=new Rectangle(2,3);
        Shape s3=new Rectangle(2,3,"red",false);
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);
        s1.setColor("pink");
        s2.setFilled(false);
        ((Rectangle) s3).setLength(8);
        ((Rectangle) s3).setWidth(6);
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);
        System.out.println(((Rectangle) s3).getPerimeter());
        System.out.println(((Rectangle) s3).getArea());
    }
}

package Exercise3_1;

public class Circle extends Shape {
    private double radius;
    Circle(){
        super();
        this.radius=1.0;
    }
    Circle(double radius,String color,boolean filled){
        super(color,filled);
        this.radius=radius;
    }
    Circle(double radius){
        super();
        this.radius=radius;
    }
    double getRadius(){
        return radius;
    }
    void setRadius(double radius){
        this.radius=radius;
    }
    double getArea(){
        return Math.PI*radius*radius;
    }
    double getPerimeter(){
        return 2*Math.PI*radius;
    }
    public String toString(){
        String Res="A Circle with radius="+radius+", which is a subclass of "+super.toString();
        return Res;
    }
    public static void main(String[] args){
        Shape s1=new Circle();
        Shape s2=new Circle(2);
        Shape s3=new Circle(2,"red",false);
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);
        s1.setColor("yellow");
        s2.setFilled(false);
        ((Circle) s3).setRadius(5);
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);
        System.out.println(((Circle) s3).getArea());
        System.out.println(((Circle) s3).getPerimeter());
        System.out.println(s3.isFilled());
    }
}

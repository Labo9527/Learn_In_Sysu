package Exercise3_2;

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

}

package Exercise2_2;

public class Circle2D {
    private double x;
    private double y;
    private double radius;

    public double getArea(){
        return radius*radius*Math.PI;
    }

    public Circle2D(){
        x=0;
        y=0;
        radius=1;
    }

    private double Abs(double a){
        if(a>0)
            return -a;
        else
            return a;
    }

    public boolean contains(Circle2D circle){
        return Math.sqrt(Math.pow(Abs(x-circle.x),2)+Math.pow(Abs(y-circle.y),2))<=(radius-circle.radius);
    }

    public boolean contains(double a,double b){
        return Math.sqrt(Math.pow(Abs(x-a),2)+Math.pow(Abs(y-b),2))<=radius;
    }

    public boolean overlaps(Circle2D circle){
        return Math.sqrt(Math.pow(Abs(x-circle.x),2)+Math.pow(Abs(y-circle.y),2))<(radius+circle.radius)&&!contains(circle)&&!circle.contains(this);
    }

    public double getPerimeter() {
        return 2*Math.PI*radius;
    }

    public Circle2D(double a,double b,double c){
        x=a;
        y=b;
        radius=c;
    }

    public double getX(){
        return x;
    }

    public double getY() {
        return y;
    }

    public double getRadius() {
        return radius;
    }
    public static void main(String[] args){
        Circle2D c1=new Circle2D(2,2,5.5);
        System.out.println(c1.getArea());
        System.out.println(c1.getPerimeter());
        System.out.println(c1.contains(3,3));
        System.out.println(c1.contains(new Circle2D(4,5,10.5)));
        System.out.println(c1.overlaps(new Circle2D(3,5,2.3)));
    }
}
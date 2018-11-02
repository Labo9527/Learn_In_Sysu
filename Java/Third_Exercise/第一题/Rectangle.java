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
}

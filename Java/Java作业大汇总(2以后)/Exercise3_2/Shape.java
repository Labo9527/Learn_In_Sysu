package Exercise3_2;

public abstract class Shape{
    protected String color;
    protected boolean filled;
    String getColor(){
        return color;
    }
    boolean isFilled(){
        return filled;
    }
    void setColor(String color){
        this.color=color;
    }
    void setFilled(boolean filled){
        this.filled=filled;
    }
    public String toString(){
        String Res = "A Shape with "+color+" and";
        if(filled)
            return Res+" filled";
        else
            return Res+" Not filled";
    }
    Shape(){
        color="green";
        filled=false;
    }
    Shape(String color,boolean filled){
        this.filled=filled;
        this.color=color;
    }
    abstract double getArea();
    abstract double getPerimeter();
}
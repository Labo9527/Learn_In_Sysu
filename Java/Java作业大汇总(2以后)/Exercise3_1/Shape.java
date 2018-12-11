package Exercise3_1;

public class Shape {
    private String color;
    private boolean filled;
    Shape(){
        color="green";
        filled=true;
    }
    Shape(String color,boolean filled){
        this.filled=filled;
        this.color=color;
    }
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

    public static void main(String[] args){
        Shape s1=new Shape();
        Shape s2=new Shape("red",false);
        System.out.println(s1);
        System.out.println(s2);
        s1.setColor("black");
        s2.setFilled(true);
        System.out.println(s1);
        System.out.println(s2);
    }
}

public class Main {

    private static void test1(){

        Shape One = new Shape();
        System.out.println(One.toString());
        One.setColor("red");
        One.setFilled(true);
        System.out.println(One.toString());
        One = new Shape("yellow",true);
        System.out.println(One);
        System.out.println("Color:"+One.getColor());
        System.out.println("Filled:"+One.isFilled());

        Circle Two=new Circle();
        System.out.println(Two.toString());
        Two = new Circle(3.1,"yellow",true);
        System.out.println(Two.toString());
        Two.setRadius(998);
        System.out.println(Two.toString());

        Rectangle Three=new Rectangle();
        System.out.println(Three.toString());
        Three=new Rectangle(1.2,4.5,"pink",true);
        System.out.println(Three.toString());

        Square Four=new Square();
        System.out.println(Four.toString());
        Four=new Square(3.2);
        System.out.println(Four.toString());

    }


    public static void main(String[] args) {
        test1();
    }
}

package com.company;

public class Main {

    public static void Test1(){
        System.out.println("Test 1:");
        MyInteger Test1=new MyInteger(5);
        System.out.printf("Value : %d\n",Test1.getter());
        System.out.println(MyInteger.isEven(3));
        System.out.println(MyInteger.isEven(4));
        System.out.println(MyInteger.isOdd(3));
        System.out.println(MyInteger.isOdd(4));
        System.out.println(MyInteger.isPrime(17));
        System.out.println(Test1.equals(5));
        System.out.println(Test1.equals(6));
        System.out.println(Test1.equals(new MyInteger(3)));
    }

    public static void Test2(){
        Circle2D One=new Circle2D(0,0,3);
        Circle2D Two=new Circle2D(3,3,1);
        System.out.println(Two.getArea());
        System.out.println(One.getPerimeter());
        One.overlaps(Two);
        One.contains(Two);
        One.contains(1,1);
    }

    public static void Test3(){
        Vehicle One=new Vehicle(1,2,3,4,5,6,new engine(1,2,3,4));
        PureElectricVehicle Two=new PureElectricVehicle(1,2,3,4,5,6,new engine(1,2,3,4),1,2);
        NewEnergyVehicle Three=new NewEnergyVehicle(1,2,3,4,5,6,new engine(1,2,3,4),3);
        One.print();
        Two.print();
        Three.print();
    }

    public static void Test4(){
        MyDate T=new MyDate(2000,1,1);
        System.out.println(T.toString());
    }

    public static void main(String[] args) {
        Test1();
        Test2();
        Test3();
        Test4();
    }
}

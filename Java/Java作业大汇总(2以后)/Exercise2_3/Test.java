package Exercise2_3;

public class Test {
    public static void main(String[] args){
        Vehicle v1=new Vehicle(1,2,3,4,5,6,new engine(1,2,3,4));
        v1.print();
        v1=new NewEnergyVehicle(1,2,3,4,5,6,new engine(1,2,3,4),7);
        System.out.println("----------------------------");
        v1.print();
        v1=new PureElectricVehicle(1,2,3,4,5,6,new engine(1,2,3,4),1,2);
        System.out.println("----------------------------");
        v1.print();
    }
}

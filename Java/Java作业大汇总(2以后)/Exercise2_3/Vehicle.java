package Exercise2_3;

public class Vehicle {
    public int model_number;
    public int seating_capacity;
    public int tire_size;
    public int length;
    public int width;
    public int height;
    public engine my_egine;

    Vehicle(int Model,int Seat,int Tire,int Leng,int Widt,int Heig,engine MyeNG){
        model_number=Model;
        seating_capacity=Seat;
        tire_size=Tire;
        length=Leng;
        width=Widt;
        height=Heig;
        my_egine=MyeNG;
    }

    public void print(){
        System.out.printf("Model Number is %d\n",model_number);
        System.out.printf("Seating Capacity is %d\n",seating_capacity);
        System.out.printf("Tire Size is %d\n",tire_size);
        System.out.printf("Length is %d\n",length);
        System.out.printf("Width is %d\n",width);
        System.out.printf("Height is %d\n",height);
        System.out.println("About engine:");
        System.out.printf("Discharge is %d , Power is %d , Torque is %d, Number of Cylinders is %d\n",my_egine.discharge_capacity,my_egine.power,my_egine.torque,my_egine.number_of_cylinders);
    }
}
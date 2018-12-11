package Exercise2_3;

public class PureElectricVehicle extends NewEnergyVehicle {
    public int MaximumRange;

    PureElectricVehicle(int Model,int Seat,int Tire,int Leng,int Widt,int Heig,engine MyeNG,int Batt,int MaxmumR){
        super(Model,Seat,Tire,Leng,Widt,Heig,MyeNG,Batt);
        MaximumRange=MaxmumR;
    }

    public void print(){
        System.out.printf("Model Number is %d\n",model_number);
        System.out.printf("Seating Capacity is %d\n",seating_capacity);
        System.out.printf("Tire Size is %d\n",tire_size);
        System.out.printf("Length is %d\n",length);
        System.out.printf("Width is %d\n",width);
        System.out.printf("Height is %d\n",height);
        System.out.printf("Battery Capacity is %d\n",battery);
        System.out.printf("Maximum Range is %d\n",MaximumRange);
        System.out.println("About engine:");
        System.out.printf("Discharge is %d , Power is %d , Torque is %d, Number of Cylinders is %d\n",my_egine.discharge_capacity,my_egine.power,my_egine.torque,my_egine.number_of_cylinders);
    }
}
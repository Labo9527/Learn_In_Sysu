package Exercise4_4;

public class Test {
    public static void main(String args[]){
        BankSystem B=new BankSystem("B");
        BankSystem C=new BankSystem("C");
        Thread K1=new Thread(B);
        Thread K2=new Thread(C);
        K1.start();
        K2.start();
        try{
            K1.join();
            K2.join();
        }
        catch (Exception e1){
            e1.printStackTrace();
        }
        int one,two;
        one=100000000-BankSystem.B.Money;
        two=100000000-BankSystem.C.Money;
        System.out.println("B to A in total:"+one);
        System.out.println("C to A in total:"+two);
        System.out.println("A has "+BankSystem.A.Money+" in total");
    }
}

package Exercise4_4;

public class BankSystem implements Runnable {
    public static Account A=new Account(100,"A");
    public static Account B=new Account(100000000,"B");
    public static Account C=new Account(100000000,"C");
    private String J;
    BankSystem(String k){
        this.J=k;
    }
    public void run(){
        for(int i=0;i<1000;i++) {
            try {
                Thread.sleep(1);
                synchronized (A) {
                    if (J == "B") {
                        int tra=(int)(Math.random()*10000);
                        B.Money -= tra;
                        A.Money += tra;
                        System.out.println("B transfer $"+String.format("%04d",tra)+" to A.         the balance of A: " + A.Money);
                    } else {
                        int tra=(int)(Math.random()*10000);
                        C.Money -= tra;
                        A.Money += tra;
                        System.out.println("C transfer $"+String.format("%04d",tra)+" to A.         the balance of A: " + A.Money);
                    }
                }
            }
            catch (Exception e){
                e.printStackTrace();
            }
        }
    }
}
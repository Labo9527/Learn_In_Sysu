package Exercise4_5;

public class Fork {
    public int number;
    public static int[] fork={0,0,0,0,0};
    Fork(int x){
        number=x;
    }
//    public synchronized void use(){
//        try {
//            Thread.sleep(1000);
//            fork[number - 1] = 1;
//        }
//        catch (InterruptedException e){
//            e.printStackTrace();
//        }
//    }
    public synchronized void use(){
        while(true) {
            fork[number - 1] = 1;
            if(fork[number%5]==0)
                break;
        }
    }
    public synchronized void put(){
        fork[number-1]=0;
    }
}

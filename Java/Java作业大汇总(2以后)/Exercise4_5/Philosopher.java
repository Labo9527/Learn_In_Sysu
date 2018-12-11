package Exercise4_5;

public class Philosopher extends Thread {
    private String name;
    private Fork left;
    private Fork right;
    Philosopher(String n,Fork a,Fork b){
        name=n;
        left=a;
        right=b;
    }
    public void run() {
        eat();
    }

    public void eat(){
        try {
            if(Fork.fork[left.number-1]==0)
                left.use();
            if(Fork.fork[right.number-1]==0)
                right.use();
            System.out.println(name + " is eatting.");
            Thread.sleep(1000);
            left.put();
            right.put();
        }
        catch (InterruptedException e){
            e.printStackTrace();
        }
    }
}

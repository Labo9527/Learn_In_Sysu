package Philosopher;

public class Philosopher implements Runnable {
    private Fork left;
    private Fork right;
    private String name;

    public Philosopher(Fork l,Fork r, String n){
        left=l;
        right=r;
        name=n;
        System.out.println(name);
    }

    private void pause() throws InterruptedException{
        Thread.sleep(0);//0易发生死锁
    }

    @Override
    public void run() {
        try{
            while(!Thread.interrupted()){
                System.out.println(this+" "+"thinking");
                pause();
                right.use();
                left.use();
                System.out.println(this+" "+"eating");
                pause();
                right.put();
                left.put();
            }
        }
        catch (InterruptedException e){
            e.printStackTrace();
        }
    }

    public String toString(){
        return "Philosopher----"+name;
    }

}

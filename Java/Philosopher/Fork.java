package Philosopher;

public class Fork {
    private boolean beingUsed=false;
    Fork(){

    }
    public synchronized void use() throws InterruptedException {
        while(beingUsed) {
            wait();
        }
        beingUsed=true;
    }
    public synchronized void put(){
        beingUsed=false;
        notifyAll();
    }
}

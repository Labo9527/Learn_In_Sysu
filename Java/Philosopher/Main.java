package Philosopher;

public class Main {
    public static void main(String[] args) {
        Fork[] Forks = new Fork[5];
        Forks[0] = new Fork();
        Forks[1] = new Fork();
        Forks[2] = new Fork();
        Forks[3] = new Fork();
        Forks[4] = new Fork();
        Philosopher A = new Philosopher(Forks[0], Forks[1], "A");
        Philosopher B = new Philosopher(Forks[1], Forks[2], "B");
        Philosopher C = new Philosopher(Forks[2], Forks[3], "C");
        Philosopher D = new Philosopher(Forks[3], Forks[4], "D");
        //Philosopher E = new Philosopher(Forks[4], Forks[0], "E");   //Dead
        Philosopher E=new Philosopher(Forks[0],Forks[4],"E");   //Not Dead
        Thread one = new Thread(A);
        Thread two = new Thread(B);
        Thread thr = new Thread(C);
        Thread fou = new Thread(D);
        Thread fiv = new Thread(E);
        one.start();
        two.start();
        thr.start();
        fou.start();
        fiv.start();
    }
}

package Exercise4_5;

public class Test1 {
    public static void main(String[] args) {
        Fork a = new Fork(1);
        Fork b = new Fork(2);
        Fork c = new Fork(3);
        Fork d = new Fork(4);
        Fork e = new Fork(5);
        Philosopher A = new Philosopher("A", a, b);
        Philosopher B = new Philosopher("B", b, c);
        Philosopher C = new Philosopher("C", c, d);
        Philosopher D = new Philosopher("D", d, e);
        Philosopher E = new Philosopher("E", e, a);
        A.start();
        B.start();
        C.start();
        D.start();
        E.start();
    }
}

package Exercise2_1;

public class MyInteger {
    private int value;
    public MyInteger(int T){
        value=T;
    }
    public int getter(){
        return value;
    }
    public boolean isEven(){
        return (value%2)==0;
    }
    public boolean isOdd(){
        return (value%2)==1;
    }
    public boolean isPrime(){
        for(int i=2;i<=Math.sqrt(value);i++){
            if(value%i==0)
                return false;
        }
        return true;
    }
    public static boolean isEven(int T){
        return (T%2)==0;
    }
    public static boolean isOdd(int T){
        return (T%2)==1;
    }
    public static boolean isPrime(int T){
        for(int i=2;i<=Math.sqrt(T);i++){
            if(T%i==0)
                return false;
        }
        return true;
    }
    public boolean equals(int T){
        return value==T;
    }
    public boolean equals(MyInteger T){
        return value==T.value;
    }
    public static boolean isEven(MyInteger T){
        return (T.value%2)==0;
    }
    public static boolean isOdd(MyInteger T){
        return (T.value%2)==1;
    }
    public static boolean isPrime(MyInteger T){
        for(int i=2;i<=Math.sqrt(T.value);i++){
            if(T.value%i==0)
                return false;
        }
        return true;
    }
    public static void main(String[] args){
        MyInteger s=new MyInteger(3);
        System.out.println(s.getter());
        System.out.println(isEven(s.getter()));
        System.out.println(isOdd(s.getter()));
        System.out.println(isPrime(s.getter()));
        System.out.println(s.isEven());
        System.out.println(s.isOdd());
        System.out.println(s.isPrime());
        System.out.println(isEven(s));
        System.out.println(isOdd(s));
        System.out.println(isPrime(s));
    }
}
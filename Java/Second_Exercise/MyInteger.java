package com.company;

public class MyInteger {
    private int value;
    public MyInteger(int T){
        value=T;
    }
    public int getter(){
        return value;
    }
    public static boolean isEven(int T){
        return (T%2)==0;
    }
    public static boolean isOdd(int T){
        return (T%2)==1;
    }
    public static boolean isPrime(int T){
        for(int i=1;i<=Math.sqrt(T);i++){
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
}

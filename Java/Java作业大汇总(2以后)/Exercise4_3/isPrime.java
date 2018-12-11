package Exercise4_3;

public class isPrime {
    public boolean TestisPrime(int a){
        if(a==2)
            return true;
        for(int i=2;i<=Math.sqrt(a);i++) {
            if (a % i == 0)
                return false;
        }
        return true;
    }
}

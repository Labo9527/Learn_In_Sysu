package Exercise4_3;

public class Labor extends Thread{
    public int a;
    public int b;
    public Labor(int a,int b){
        this.a=a;
        this.b=b;
    }
    public void run(){
        isPrime test=new isPrime();
        for(int i=a;i<b;i++){
            if(test.TestisPrime(i))
                System.out.println(i);
        }
    }
}

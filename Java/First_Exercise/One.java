import java.util.Scanner;

public class One{
    public static Scanner s=new Scanner(System.in);
    public void Run(){
        int counter;
        counter=s.nextInt();
        for(int i=1;i<=counter;i++){
            for(int j=0;j<counter-i;j++){
                System.out.print(" ");
            }
            int out=i;
            boolean di=true;
            for(int j=0;j<2*i-1;j++){
                System.out.print(out);
                if(di){
                    out--;
                }
                else{
                    out++;
                }
                if(out==0){
                    out=2;
                    di=false;
                }
            }
            System.out.print("\n");
        }
    }
}
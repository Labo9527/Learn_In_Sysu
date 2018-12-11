package Exercise4_2;

import java.util.Scanner;

public class Test {
    public static void main(String args[]){
        int[] Array=new int[100];
        Scanner sc=new Scanner(System.in);
        int command;
        for(int i=0;i<100;i++)
            Array[i]=(int)(Math.random()*1000);
        while(true){
            System.out.println("Enter a Number to Get Array[x]  (100 to exit)");
            command=sc.nextInt();
            if(command==100)
                return;
            try {
                if(command>100)
                    throw new IndexOutOfBoundsException("数组越界");
                System.out.println(Array[command]);
            }
            catch (Exception e){
                e.printStackTrace();
                return;
            }
        }
    }
}

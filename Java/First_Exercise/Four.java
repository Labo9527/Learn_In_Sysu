import java.util.Scanner;

public class Four {
    public static Scanner s=new Scanner(System.in);
    public void Run(){
        float Sum=1.1f;
        int[] coins={0,5,10,20,50,100,200,500,1000,2000,5000,10000};
        while(Sum!=0.00) {
            Sum = s.nextFloat();
            if(Sum==0.0)
                break;
            int SUM=(int)(Sum*100);
            int [][]dp =new int[12][SUM+1];
            for(int i=0;i<=11;i++){
                dp[i][0]=1;
            }
            for(int i=1;i<=11;i++){
                for(int j=5;j<=SUM;j+=5){
                    for(int k=0;k<=j/coins[i];k++){
                        dp[i][j]+=dp[i-1][j-coins[i]*k];
                    }
                }
            }
            System.out.println(dp[11][SUM]);
        }
    }
}

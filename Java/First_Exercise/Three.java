import java.util.Calendar;
import java.util.Scanner;

public class Three {
    public static Scanner s=new Scanner(System.in);
    public void Run(){
        Calendar C=Calendar.getInstance();
        int year,month,day,hour;
        year=C.get(Calendar.YEAR);
        month=C.get(Calendar.MONTH);
        day=C.get(Calendar.DATE);
        hour=C.get(Calendar.HOUR);
        System.out.printf("%02d-%02d-%02d %02dh\n",year,month,day,hour);
        System.out.printf("现在是%d年",year);
        switch (month){
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6: System.out.printf("上半年, %d月",month);break;
            default:System.out.printf("下半年, %d月",month); break;
        }
        if(day<=10){
            System.out.printf("上旬");
        }
        else if(day>10&&day<=20){
            System.out.printf("中旬");
        }
        else if(day>20){
            System.out.printf("下旬");
        }
        if(hour>0&&hour<=5){
            System.out.printf("凌晨\n");
        }
        else if(hour>5&&hour<=10){
            System.out.printf("早上\n");
        }
        else if(hour>10&&hour<=12){
            System.out.printf("中午\n");
        }
        else if(hour>12&&hour<=17){
            System.out.printf("下午\n");
        }
        else if(hour>17&&hour<=23){
            System.out.printf("晚上\n");
        }
    }
}

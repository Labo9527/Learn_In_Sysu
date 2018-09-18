import java.util.Scanner;

public class Two {
    public static Scanner s=new Scanner(System.in);
    public void Run(){
        String Line=s.nextLine();
        StringBuilder sb1=new StringBuilder(Line);
        String buffer=new String("");
        StringBuilder sb2=new StringBuilder(buffer);
        int start=0;
        for(int i=0;i<=Line.length();i++){
            if(i==Line.length()||Line.charAt(i)==' '){
                for(int j=0;j<buffer.length();j++){
                    sb1.setCharAt(j+start,buffer.charAt(j));
                }
                start=i+1;
                sb2.delete(0,sb2.length());
                buffer="";
            }
            else{
                sb2.insert(0,Line.charAt(i));
                buffer=sb2.toString();
            }
        }
        Line=sb1.toString();
        System.out.println(Line);
    }
}

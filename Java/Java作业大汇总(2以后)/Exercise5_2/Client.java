package Exercise5_2;

import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;
import java.net.InetAddress;

public class Client {
    private static Socket receive;
    private static Scanner Out;
    private static Scanner In;
    private static PrintWriter Pw;
    public static void main(String[] args){
        try {
            receive = new Socket("127.0.0.1", 8080);
            Out=new Scanner(System.in);
            In=new Scanner(receive.getInputStream());
            Pw=new PrintWriter(receive.getOutputStream());
            Thread One=new Thread(new Runnable() {
                @Override
                public void run() {
                    while(In.hasNextLine()) {
                        String Msg = In.nextLine();
                        if (Msg.length() >= 1)
                            System.out.println("Server(Others):" + Msg);
                    }
                }
            });
            Thread Two=new Thread(new Runnable() {
                @Override
                public void run() {
                    while(Out.hasNextLine()) {
                        String Send = Out.nextLine();
                        if (Send.length() >= 1) {
                            Pw.println(Send);
                            Pw.flush();
                        }
                    }
                }
            });
            One.start();
            Two.start();
//            while (In.hasNextLine()){
//                String Msg=In.nextLine();
//                if(Msg.length()>=1)
//                    System.out.println("Server(Others):"+Msg);
//                String Send=Out.nextLine();
//                if(Send.length()>=1){
//                    Pw.println(Send);
//                    Pw.flush();
//                }
//            }
        }
        catch (Exception e){
            System.out.println("Exceptioin: "+e);
        }
    }
}

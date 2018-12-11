package Exercise5_2;

import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Server {
    private static ServerSocket Server;
    private static Socket receive;
    private static Scanner Out;
    private static Scanner In;
    private static PrintWriter Pw;
    public static void main(String[] args){
        try{
            Server=new ServerSocket(8080);
            System.out.println("创建服务器成功");
            receive=Server.accept();
            Pw=new PrintWriter(receive.getOutputStream());
            Out=new Scanner(System.in);
            In=new Scanner(receive.getInputStream());
            Pw.println("已成功连接");
            Pw.flush();
            System.out.println("Yes");
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
//            while(In.hasNextLine()){
//                String Msg="",Send="";
//                if(In.hasNextLine())
//                    Msg=In.nextLine();
//                if(Msg.length()>=1)
//                    System.out.println("Client(Others):"+Msg);
//                if(Out.hasNextLine())
//                    Send=Out.nextLine();
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

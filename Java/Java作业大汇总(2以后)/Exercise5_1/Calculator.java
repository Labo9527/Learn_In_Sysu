package Exercise5_1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

public class Calculator {
    private static ScriptEngineManager manager = new ScriptEngineManager();
    private static ScriptEngine se = manager.getEngineByName("js");
    private static JFrame frame;
    private static Container pane;
    private static JButton Button1;
    private static JButton Button2;
    private static JButton Button3;
    private static JButton Button4;
    private static JButton Button5;
    private static JButton Button6;
    private static JButton Button7;
    private static JButton Button8;
    private static JButton Button9;
    private static JButton Button0;
    private static JButton ButtonAdd;
    private static JButton ButtonSub;
    private static JButton ButtonMul;
    private static JButton ButtonDiv;
    private static JButton ButtonDot;
    private static JButton ButtonEqual;
    private static JLabel Text;
    private static void init(){
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(420,500);
        frame.setResizable(false);
        pane.add(Button7);
        Button7.setBounds(20,100,75,75);
        Button7.setFont(new Font("Dialog",1,35));
        Button7.setFocusPainted(false);
        Button7.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"7");
            }
        });
        pane.add(Button8);
        Button8.setBounds(115,100,75,75);
        Button8.setFont(new Font("Dialog",1,35));
        Button8.setFocusPainted(false);
        Button8.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"8");
            }
        });
        pane.add(Button9);
        Button9.setBounds(210,100,75,75);
        Button9.setFont(new Font("Dialog",1,35));
        Button9.setFocusPainted(false);
        Button9.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"9");
            }
        });
        pane.add(ButtonDiv);
        ButtonDiv.setBounds(305,100,75,75);
        ButtonDiv.setFont(new Font("Dialog",1,35));
        ButtonDiv.setFocusPainted(false);
        ButtonDiv.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"/");
            }
        });
        pane.add(Button4);
        Button4.setBounds(20,195,75,75);
        Button4.setFont(new Font("Dialog",1,35));
        Button4.setFocusPainted(false);
        Button4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"4");
            }
        });
        pane.add(Button5);
        Button5.setBounds(115,195,75,75);
        Button5.setFont(new Font("Dialog",1,35));
        Button5.setFocusPainted(false);
        Button5.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"5");
            }
        });
        pane.add(Button6);
        Button6.setBounds(210,195,75,75);
        Button6.setFont(new Font("Dialog",1,35));
        Button6.setFocusPainted(false);
        Button6.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"6");
            }
        });
        pane.add(ButtonMul);
        ButtonMul.setBounds(305,195,75,75);
        ButtonMul.setFont(new Font("Dialog",1,35));
        ButtonMul.setFocusPainted(false);
        ButtonMul.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"*");
            }
        });
        pane.add(Button1);
        Button1.setBounds(20,290,75,75);
        Button1.setFont(new Font("Dialog",1,35));
        Button1.setFocusPainted(false);
        Button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"1");
            }
        });
        pane.add(Button2);
        Button2.setBounds(115,290,75,75);
        Button2.setFont(new Font("Dialog",1,35));
        Button2.setFocusPainted(false);
        Button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"2");
            }
        });
        pane.add(Button3);
        Button3.setBounds(210,290,75,75);
        Button3.setFont(new Font("Dialog",1,35));
        Button3.setFocusPainted(false);
        Button3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"3");
            }
        });
        pane.add(ButtonSub);
        ButtonSub.setBounds(305,290,75,75);
        ButtonSub.setFont(new Font("Dialog",1,35));
        ButtonSub.setFocusPainted(false);
        ButtonSub.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"-");
            }
        });
        pane.add(Button0);
        Button0.setBounds(20,385,75,75);
        Button0.setFont(new Font("Dialog",1,35));
        Button0.setFocusPainted(false);
        Button0.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"0");
            }
        });
        pane.add(ButtonDot);
        ButtonDot.setBounds(115,385,75,75);
        ButtonDot.setFont(new Font("Dialog",1,35));
        ButtonDot.setFocusPainted(false);
        ButtonDot.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+".");
            }
        });
        pane.add(ButtonEqual);
        ButtonEqual.setBounds(210,385,75,75);
        ButtonEqual.setFont(new Font("Dialog",1,35));
        ButtonEqual.setFocusPainted(false);
        ButtonEqual.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    String Res=se.eval(Text.getText()).toString();
                    Text.setText(Res);
                } catch (ScriptException er) {
                    er.printStackTrace();
                }
            }
        });
        pane.add(ButtonAdd);
        ButtonAdd.setBounds(305,385,75,75);
        ButtonAdd.setFont(new Font("Dialog",1,35));
        ButtonAdd.setFocusPainted(false);
        ButtonAdd.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Text.setText(Text.getText()+"+");
            }
        });
        pane.add(Text);
        Text.setBounds(60,20,300,50);
        Text.setFont(new Font("Dialog",1,20));
        Text.setBackground(Color.WHITE);
        Text.setOpaque(true);
        Text.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        frame.setVisible(true);
    }
    Calculator(){
        frame=new JFrame();
        pane=frame.getContentPane();
        Button1=new JButton("1");
        Button2=new JButton("2");
        Button3=new JButton("3");
        Button4=new JButton("4");
        Button5=new JButton("5");
        Button6=new JButton("6");
        Button7=new JButton("7");
        Button8=new JButton("8");
        Button9=new JButton("9");
        Button0=new JButton("0");
        ButtonAdd=new JButton("+");
        ButtonSub=new JButton("-");
        ButtonMul=new JButton("*");
        ButtonDiv=new JButton("/");
        ButtonDot=new JButton(".");
        ButtonEqual=new JButton("=");
        Text=new JLabel("",SwingConstants.CENTER);
        init();
    }

    public static void main(String[] args) {
        Calculator C=new Calculator();
    }
}

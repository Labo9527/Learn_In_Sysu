import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.beans.PropertyChangeListener;

public class WindowRelated {
    private static JFrame frame;
    private static Container pane;
    private static Board board;
    private static JButton regret;
    private static JButton restart;
    private static Timer CountTime;
    private static JLabel ShowTime;
    private static JLabel White;
    private static JLabel Black;
    private static int Time;

    private static void createGUI(){
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600,484);
        frame.setResizable(false);
        pane.add(board);
        board.setBounds(0,0,450,484);
        pane.add(regret);
        regret.setBounds(450,0,150,100);
        regret.setFont(new Font("Dialog",1,15));
        regret.setBackground(Color.CYAN);
        regret.setFocusPainted(false);
        pane.add(restart);
        restart.setBounds(450,100,150,100);
        restart.setFont(new Font("Dialog",1,15));
        restart.setBackground(Color.CYAN);
        restart.setFocusPainted(false);
        pane.add(ShowTime);
        ShowTime.setBounds(450,200,150,100);
        ShowTime.setOpaque(true);
        ShowTime.setBackground(Color.CYAN);
        ShowTime.setFont(new Font("Dialog",1,15));
        pane.add(White);
        White.setOpaque(true);
        White.setBounds(450,300,150,80);
        White.setFont(new Font("Dialog",1,15));
        White.setBackground(Color.WHITE);
        White.setForeground(Color.BLACK);
        pane.add(Black);
        Black.setOpaque(true);
        Black.setBounds(450,380,150,80);
        Black.setFont(new Font("Dialog",1,15));
        Black.setBackground(Color.BLACK);
        Black.setForeground(Color.WHITE);
        CountTime.start();
        restart.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Time=0;
                board.Restart();
                ShowTime.setText("游戏开始："+Time+"s");
            }
        });
        //JOptionPane.showMessageDialog(null,"你赢了");
        frame.setVisible(true);
    }

    WindowRelated(){
        Time=0;
        frame=new JFrame("FiveChess");
        pane=frame.getContentPane();
        board=new Board();
        regret=new JButton("悔棋");
        restart=new JButton("重新开始");
        White=new JLabel("玩家");
        Black=new JLabel("电脑");
        ShowTime=new JLabel("游戏开始："+Time+"s",SwingConstants.CENTER);
        CountTime=new Timer(1000, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(!board.End)
                    Time=Time+1;
                ShowTime.setText("游戏开始："+Time+"s");
            }
        });
        createGUI();
    }

}

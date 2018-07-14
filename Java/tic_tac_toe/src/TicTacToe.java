import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Андрей on 22.07.2017.
 */
public class TicTacToe extends JFrame {
    public TicTacToe(){
        setTitle("Крестики-нолики");
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setSize(400,450);

        JPanel jBottomPanel = new JPanel();
        jBottomPanel.setLayout(new GridBagLayout());
        JButton jButtonStart = new JButton("Новая игра");
        JButton jButtonEnd = new JButton("Выход");
        JLabel labelPlay = new JLabel("Выберите, чем играть");
        ButtonGroup group = new ButtonGroup();

        JRadioButton radioButtonX = new JRadioButton("X",true);
        radioButtonX.isSelected();
        group.add(radioButtonX);
        JRadioButton radioButton0 = new JRadioButton("0");
        group.add(radioButton0);
        jBottomPanel.add(labelPlay);
        jBottomPanel.add(radioButtonX);
        jBottomPanel.add(radioButton0);
        jBottomPanel.add(jButtonStart);
        jBottomPanel.add(jButtonEnd);
        jButtonStart.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                GameLogic.flag=true;
                GameField gf1 = new GameField();
                add(gf1,BorderLayout.CENTER);
                setVisible(true);
                if (radioButtonX.isSelected()) {
                    GameLogic.setHumanSymb('X');
                    GameLogic.setAiSymb('0');
                }
                if (radioButton0.isSelected()) {
                    GameLogic.setHumanSymb('0');
                    GameLogic.setAiSymb('X');
                }
                GameField gf = new GameField();
                add(gf,BorderLayout.CENTER);
                //repaint();
                setVisible(true);
            }
        });
        jButtonEnd.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        add(jBottomPanel, BorderLayout.SOUTH);
        GameLogic.setHumanSymb('X');//задание по умолчанию
        GameLogic.setAiSymb('0');//задание по умолчанию
        GameField gf = new GameField();
        add(gf,BorderLayout.CENTER);
        setLocationRelativeTo(null);
        setVisible(true);
    }
}

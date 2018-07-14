import com.sun.nio.sctp.MessageInfo;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Random;

/**
 * Created by Андрей on 22.07.2017.
 */
public class GameField extends JPanel {
    private int width;
    private int height;
    private int cellWidth;
    private int cellHeight;
    private static char[][] map;

    public GameField(){
        Map map1 = new Map();
        map = map1.getMap();
        GameLogic.initStart();
        GameLogic.gameLogic(map1,GameLogic.move);
        setBackground(Color.WHITE);
        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseReleased(MouseEvent e) {
                //System.out.println(e.getX() + " " + e.getY());
                int clX = e.getX() / cellWidth;
                int clY = e.getY() / cellHeight;
                GameLogic.gameLogic(clX,clY,map1,GameLogic.move);
                repaint();
                GameLogic.gameLogic(clX,clY,map1,GameLogic.move);
                repaint();
                if (GameLogic.isMapFull(map1))
                    JOptionPane.showMessageDialog(null, "Ничья!");
                if (GameLogic.checkWin(map1,GameLogic.getAiSymb()))
                    JOptionPane.showMessageDialog(null, "Победил компьютер!");
                if (GameLogic.checkWin(map1,GameLogic.getHumanSymb()))
                    JOptionPane.showMessageDialog(null, "Победил человек!");
            }
        });
    }

    protected void paintComponent(Graphics g){
        g.setColor(Color.WHITE);
        width = getWidth();
        height = getHeight();
        g.fillRect(0,0,width,height);
        cellHeight = height/map.length;
        cellWidth = width/map.length;
        g.setColor(Color.BLACK);
        for(int i = 0; i<map.length;i++) {
            g.drawLine(0,i*cellHeight,width,i*cellHeight);
            g.drawLine(i*cellWidth,0,i*cellWidth,height);
        }
        for (int i=0;i<map.length;i++){
            for (int j=0;j<map.length;j++){
                if (map[i][j]=='0'){
                    g.setColor(Color.RED);
                    g.drawOval(i*cellWidth+10,j*cellHeight+10,cellWidth-20,cellHeight-20);
                }
                if (map[i][j]=='X'){
                    g.setColor(Color.GREEN);
                    g.drawLine(i*cellWidth,j*cellHeight,(i+1)*cellWidth+1,(j+1)*cellHeight);
                    g.drawLine((i+1)*cellWidth,j*cellHeight,i*cellWidth,(j+1)*cellHeight);
                }
            }
        }
    }
}

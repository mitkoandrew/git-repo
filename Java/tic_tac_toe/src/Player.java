import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

/**
 * Created by Андрей on 24.07.2017.
 */
public class Player {
    private static int x,y;

    public Player(int x,int y){
        this.x=x;
        this.y=y;
    }
    public static void humanTurn(int x, int y, Map map, char symb){
            while (!map.checkTurn(y,x)) {
                map.setMap(x, y, symb);
            }
    }
}

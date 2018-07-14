import java.util.Random;

/**
 * Created by Андрей on 24.07.2017.
 */
public class Ai {

    public static Random random = new Random();
    public static void aiTurn(Map map, char Symb, char SymbHuman){
        //Map map = new Map();
        int SIZE = map.SIZE;
        int x = 0;
        int y = 0;
        boolean flag = false;
        boolean flag1 = false;
        int xcenter = (int) (SIZE / 2);
        int ycenter = (int) (SIZE / 2);
        do{
            if (map.getMap(ycenter,xcenter) == map.DOT_EMPTY) {x = xcenter; y =ycenter; break;}
            if (map.sumDiagonal(Symb) == map.DOTS_TO_WIN - 1) {
                for (int j = 0; j < SIZE; j++)
                    if (map.getMap(j,j) == map.DOT_EMPTY) {
                        x = j;
                        y = j;
                        flag = true;
                        break;
                    }
            }
            if (map.sumCrossDiagonal(Symb) == map.DOTS_TO_WIN - 1) {
                for (int j = 0; j < SIZE; j++)
                    if (map.getMap(j,(SIZE - 1 - j)) == map.DOT_EMPTY) {
                        x = j;
                        y = SIZE - 1 - j;
                        flag = true;
                        break;
                    }
            }
            if (map.checkHorizontal(Symb,map.DOTS_TO_WIN-1)!= -1){
                for (int i = 0; i< SIZE;i++)
                    if (map.getMap(map.checkHorizontal(Symb,map.DOTS_TO_WIN-1),i) == map.DOT_EMPTY){
                        x = map.checkHorizontal(Symb,map.DOTS_TO_WIN-1);
                        y = i;
                        flag = true;
                        break;
                    }
                // break;
            }
            if (map.checkVertical(Symb,map.DOTS_TO_WIN-1)!= -1){
                for (int i = 0; i< SIZE;i++)
                    if (map.getMap(i,map.checkVertical(Symb,map.DOTS_TO_WIN-1)) == map.DOT_EMPTY){
                        x = i;
                        y = map.checkVertical(Symb,map.DOTS_TO_WIN-1);
                        flag = true;
                        break;
                    }
            }
            if(!flag) {
                if (map.sumDiagonal(SymbHuman) == map.DOTS_TO_WIN - 1) {
                    for (int j = 0; j < SIZE; j++)
                        if (map.getMap(j,j) == map.DOT_EMPTY) {
                            x = j;
                            y = j;
                            flag1 = true;
                            break;
                        }
                }
                if (map.sumCrossDiagonal(SymbHuman) == map.DOTS_TO_WIN - 1) {
                    for (int j = 0; j < SIZE; j++)
                        if (map.getMap(j,SIZE - 1 - j) ==map.DOT_EMPTY) {
                            x = j;
                            y = SIZE - 1 - j;
                            flag1 = true;
                            break;
                        }
                }
                if (map.checkHorizontal(SymbHuman,map.DOTS_TO_WIN-1)!= -1){
                    for (int i = 0; i< SIZE;i++)
                        if (map.getMap(map.checkHorizontal(SymbHuman,map.DOTS_TO_WIN-1),i) == map.DOT_EMPTY){
                            x = map.checkHorizontal(SymbHuman,map.DOTS_TO_WIN-1);
                            y = i;
                            flag1 = true;
                            break;
                        }
                }
                if (map.checkVertical(SymbHuman,map.DOTS_TO_WIN-1)!= -1){
                    for (int i = 0; i< SIZE;i++)
                        if (map.getMap(i,map.checkVertical(SymbHuman,map.DOTS_TO_WIN-1)) == map.DOT_EMPTY){
                            x = i;
                            y = map.checkVertical(SymbHuman,map.DOTS_TO_WIN-1);
                            flag1 = true;
                            break;
                        }
                }
                if (!flag1) {
                    x = random.nextInt(SIZE);
                    y = random.nextInt(SIZE);
                }
            }
        }while(!map.checkTurn(y,x));
        System.out.println("Ход компьютера в точку " + (x+1) + " " + (y+1));
        map.setMap(x,y,Symb);
       // map.getMap(x,y) = Symb;
    }
}

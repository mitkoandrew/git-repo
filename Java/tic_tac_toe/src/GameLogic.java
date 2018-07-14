import sun.plugin2.os.windows.FLASHWINFO;

import javax.swing.plaf.PanelUI;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by Андрей on 24.07.2017.
 */public class GameLogic {
    static boolean flag = true;
    private static char humanSymb;
    private static char aiSymb;
    static int move=0;

    public static void initStart(){
        if (humanSymb == 'X')
            move=1;
        else
            move=0;
    }

    public static int plusMoves(){
        return ++move;
    }

    public static int minusMoves(){
        return ++move;
    }

    public static void setHumanSymb(char humanSymb) {
        GameLogic.humanSymb = humanSymb;
    }

    public static char getHumanSymb() {
        return humanSymb;
    }

    public static void setAiSymb(char aiSymb) {
        GameLogic.aiSymb = aiSymb;
    }

    public static char getAiSymb() {
        return aiSymb;
    }

    public static void gameLogic(int x, int y, Map map, int move1){
        if (move1 % 2 != 0) {
            if ((map.getMap(x, y) == map.DOT_EMPTY) & (flag == true)) {
                map.setMap(x, y, humanSymb);
                plusMoves();
                if (isMapFull(map)) {
                    System.out.println("Ничья!");
                    flag = false;
                    return;
                }
                if (checkWin(map, humanSymb)) {
                    System.out.println("Победил человек!");
                    flag = false;
                    return;
                }
            }
        }
            else {
            if (flag == true) {
                Ai.aiTurn(map, aiSymb, humanSymb);
                plusMoves();
                if (isMapFull(map)) {
                    System.out.println("Ничья!");
                    flag = false;
                    return;
                }
                if (checkWin(map, aiSymb)) {
                    System.out.println("Победил компьютер!");
                    flag = false;
                    return;
                }
            }
            }
    }

    public static void gameLogic(Map map,int move1){
        if (move1%2==0) {
            Ai.aiTurn(map, aiSymb, humanSymb);
            plusMoves();
            if (isMapFull(map)) {
                System.out.println("Ничья!");
                flag = false;
                return;
            }
            if (checkWin(map, aiSymb)) {
                System.out.println("Победил компьютер!");
                flag = false;
                return;
            }
        }
    }

    public static void gameLogic(int x, int y, Map map){
        if ((map.getMap(x,y) == map.DOT_EMPTY) & (flag == true)) {
                map.setMap(x, y, humanSymb);
                if (isMapFull(map)) {
                    System.out.println("Ничья!");
                    flag = false;
                    return;
                }
                if (checkWin(map, humanSymb)) {
                    System.out.println("Победил человек!");
                    flag = false;
                    return;
                }
                Ai.aiTurn(map, aiSymb, humanSymb);
                if (isMapFull(map)) {
                    System.out.println("Ничья!");
                    flag = false;
                    return;
                }
                if (checkWin(map, aiSymb)) {
                    System.out.println("Победил компьютер!");
                    flag = false;
                    return;
                }
        }
    }

    public static void makeTurn(int x, int y, Map map){
        if (flag == true) {
            if (humanSymb == 'X') {
                if (map.getMap(x,y) == map.DOT_EMPTY)
                map.setMap(x, y, humanSymb);
                if (isMapFull(map)) {
                    System.out.println("Ничья!");
                    flag = false;
                    return;
                }
                if (checkWin(map, humanSymb)) {
                    System.out.println("Победил человек!");
                    flag = false;
                    return;
                }
            } else {
                Ai.aiTurn(map, aiSymb, humanSymb);
                if (isMapFull(map)) {
                    System.out.println("Ничья!");
                    flag = false;
                    return;
                }
                if (checkWin(map, aiSymb)) {
                    System.out.println("Победил компьютер!");
                    flag = false;
                    return;
                }
            }
        }
    }

    public static void makeTurnAi(int x, int y, Map map){
        if (flag == true) {
            if (humanSymb == 'X'){
                Ai.aiTurn(map, aiSymb, humanSymb);
                if (isMapFull(map)) {
                    System.out.println("Ничья!");
                    flag = false;
                    return;
                }
                if (checkWin(map, aiSymb)) {
                    System.out.println("Победил компьютер!");
                    flag = false;
                    return;
                }
            }
            else{
                if (map.getMap(x,y) == map.DOT_EMPTY)
                map.setMap(x, y, humanSymb);
                if (isMapFull(map)) {
                    System.out.println("Ничья!");
                    flag = false;
                    return;
                }
                if (checkWin(map, humanSymb)) {
                    System.out.println("Победил человек!");
                    flag = false;
                    return;
                }
            }
        }
    }

    public static boolean checkWin(Map map, char Symb){
        if (map.checkHorizontal(Symb,map.DOTS_TO_WIN)>=0) return true;
        if (map.checkVertical(Symb,map.DOTS_TO_WIN)>=0) return true;
        if (map.sumDiagonal(Symb) == map.DOTS_TO_WIN) return true;
        if (map.sumCrossDiagonal(Symb) == map.DOTS_TO_WIN) return true;
        return false;
    }
    public static boolean isMapFull(Map map){
        for (int i = 0; i < map.SIZE; i++)
            for (int j = 0; j < map.SIZE; j++)
                if (map.getMap(i,j) == map.DOT_EMPTY) return false;
        return true;
    }
}
import java.util.Random;
import java.util.Scanner;


/**
 * Created by Андрей on 24.07.2017.
 */

public class Map {
    private static char[][] map;
    public static final int SIZE = 3;
    public static final int DOTS_TO_WIN = 3;
    public static final char DOT_EMPTY = '*';
    public Map(){
        map = new char[SIZE][SIZE];
        //this.SIZE = size;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                map[i][j] = DOT_EMPTY;
    }

    public static char[][] getMap() {
        return map;
    }
    public char getMap(int x, int y) {
        return map[x][y];
    }

    public static void setMap(int x, int y, char value) {
        map[x][y] = value;
    }

    public void initMap(){
        //Map map = new Map();
        //map = getMap();
        map = new char[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                map[i][j] = DOT_EMPTY;
    }
    public boolean checkTurn(int x, int y){
        if (x < 0 || x >=SIZE || y<0 || y>=SIZE) return false;
        if (map[y][x] == DOT_EMPTY) return true;
        return false;
    }
    public int sumHorizontal(int x, char Symb){
        int sum = 0;
        for (int j = 0; j < SIZE; j++) {
            if (map[x][j] == Symb) sum++;
        }
        return sum;
    }
    public int sumVertical(int y, char Symb){
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            if (map[i][y] == Symb) sum++;
        }
        return sum;
    }

    public int sumDiagonal(char Symb){
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            if (map[i][i] == Symb) sum++;
        }
        return sum;
    }

    public int sumCrossDiagonal(char Symb){
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            if (map[i][SIZE -  1 - i] == Symb) sum++;
        }
        return sum;
    }

    public int checkHorizontal(char Symb, int dots){
        for (int i = 0; i < SIZE; i++) {
            if (sumHorizontal(i,Symb) == dots) return i;
        }
        return -1;
    }
    public int checkVertical(char Symb, int dots){
        for (int i = 0; i < SIZE; i++) {
            if (sumVertical(i,Symb) == dots) return i;
        }
        return -1;
    }
}

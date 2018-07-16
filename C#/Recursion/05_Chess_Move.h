#pragma once
#include <stdio.h>
#include <stdlib.h>
#define N 8
#define M 8
int board[N][M];
int sol = 0;
long counter = 0;
int st = 0;

int CheckBoard();
int SearchMove(int n, int x, int y);//новая функция
//int SearchMove(int n);
int CheckKnight(int x, int y);
int CheckKnightNew(int x, int y);
void Zero(int n, int m, int a[N][M]);
void Print(int n, int m, int a[N][M]);
void Pause(int key);

void moveKnight(){
	Zero(N, M, board);
	sol = 0;
	st = 1;
	SearchMove(1,0,0);
	system("cls");
	Print(N, M, board);
	printf("%d\n",counter);
}

//новая функция
int SearchMove(int n, int x, int y){
	//if (CheckBoard() == 0) return 0;
	//if (CheckKnightNew(x, y) == 0)
	//	return 0;
	// 64 клетки прошли. Решение найдено
	if (n == 64)
		return 1; 
	int row = x;
	int col = y;
	int row1 = x;
	int col1 = y;
	//int row, row1, col, col1;
	//for (row = 0; row<N; row++)
	//for (col = 0; col<M; col++)
	//{
	counter++;
	board[row][col] = n;
	int path[2][8] = { -2, -1, 1, 2, 2, 1, -1, -2,
		1, 2, 2, 1, -1, -2, -2, -1 };
	for (int j = 0; (!sol) && j < 8; j++){
		row = x + path[0][j];
		col = y + path[1][j];
	//for (int a = -2; a < 3;a++)
	//for (int b=-2; b < 3;b++){
		//if (abs(a) + abs(b) == 3)
		//{
			//row = x + a;
			//col = y + b; 
		if ((board[row][col] == 0) && (row >= 0) && (row < 8) && (col >= 0) && (col < 8)) {
					board[row][col] = n;
					counter++;
					//if (counter  == 5000){
					//system("cls");
					//Print(N, M, board);
					//printf("%d\n", st);
					//Pause(1);
					//st++;
					//counter = 0;
					//}
					if (SearchMove(n + 1, row, col)) return 1;
					//sol = (SearchMove(n + 1, row, col));
					//if (sol == 0) board[row][col] = 0;
					// Если мы дошли до этой строки, данное частичное решение
					// не приводит к полному.
					board[row][col] = 0;
				}
			/*system("cls");
			Print(N, M, board);
			printf("%d\n", counter);
			Pause(1);*/
	}
	return 0;
}

	/*	if (board[row - 1][col + 2] == 0 && (row - 1 >=0) && (col + 2 < 8)){
		board[row - 1][col + 2] = n;
		row1 = row - 1;
		col1 = col + 2;
		system("cls");
		Print(N, M, board);
		Pause(1);
		if (SearchMove((n + 1), row-1, col+2)) return 1;
		board[row-1][col+2] = 0;
		}

		else if ((board[row - 2][col + 1] == 0) && (row - 2 >= 0) && (col + 1 < 8) ){
		board[row - 2][col + 1] = n;
		row1 = row - 2;
		col1 = col + 1;
		system("cls");
		Print(N, M, board);
		Pause(1);
		if (SearchMove((n + 1), row - 2, col + 1)) return 1;
		board[row - 2][col + 1] = 0;
		}
		else if (board[row - 2][col - 1] == 0 && row-2 >= 0 && col - 1 >= 0){
		board[row - 2][col - 1] = n;
		row1 = row - 2;
		col1 = col - 1;
		system("cls");
		Print(N, M, board);
		Pause(1);
		if (SearchMove((n + 1), row - 2, col - 1)) return 1;
		board[row - 2][col - 1] = 0;
		}
		else if (board[row - 1][col - 2] == 0 && row - 1>=0 && col-2>=0){
		board[row - 1][col - 2] = n;
		row1 = row - 1;
		col1 = col - 2;
		system("cls");
		Print(N, M, board);
		Pause(1);
		if (SearchMove((n + 1), row - 1, col - 2)) return 1;
		board[row - 1][col - 2] = 0;
		system("cls");
		Print(N, M, board);
		Pause(1);
		}
		else if (board[row + 1][col - 2] == 0 && row+1<8 && col-2>=0){
		board[row + 1][col - 2] = n;
		row1 = row + 1;
		col1 = col - 2;
		system("cls");
		Print(N, M, board);
		Pause(1);
		if (SearchMove((n+1), row + 1, col - 2)) return 1;
		board[row + 1][col - 2] = 0;
		}
		else if (board[row + 2][col - 1] == 0 && row+2 <8 && col-1>=0){
		board[row + 2][col - 1] = n;
		row1 = row + 2;
		col1 = col - 1;
		system("cls");
		Print(N, M, board);
		Pause(1);
		if (SearchMove((n + 1), row + 2, col - 1)) return 1;
		board[row + 2][col - 1] = 0;
		}
		else if (board[row + 2][col + 1] == 0 && row+2<8 && col+1<8) {
		board[row + 2][col + 1] = n;
		row1 = row + 2;
		col1 = col + 1;
		system("cls");
		Print(N, M, board);
		Pause(1);
		if (SearchMove((n + 1), row + 2, col + 1)) return 1;
		board[row + 2][col + 1] = 0;
		}
		else if (board[row + 1][col + 2] == 0 && row+1<8 && col+2<8) {
		board[row + 1][col + 2] = n;
		row1 = row + 1;
		col1 = col + 2;
		system("cls");
		Print(N, M, board);
		Pause(1);
		if (SearchMove((n + 1), row + 1, col + 2)) return 1;
		board[row + 1][col + 2] = 0;
		}

	return 0;
}*/


int SearchMove(int n){
	if (CheckBoard() == 0) return 0;
	// 64 клетки прошли. Решение найдено
	if (n == 65) return 1;
	/*int row = x;
	int col = y;
	int row1 = x;
	int col1 = y;*/
	int row, row1, col, col1;
	for (row = 0; row<N; row++)
	for (col = 0; col<M; col++)
	{
		if (board[row][col] == 0)
			//условия перемещения - проверяем границы и идем по часовой стрелке
		{
			//Расширяем test_solution
			board[row][col] = n;
			counter++;
			//printf("%d/n", counter);
			//if (counter  == 200000*st){
				system("cls");
				Print(N, M, board);
				Pause(1);
				st++;
			//}

			// Рекурсивно проверяем, ведет ли это к решению.
			if (SearchMove(n + 1)) return 1;
			// Если мы дошли до этой строки, данное частичное решение
			// не приводит к полному.
			board[row][col] = 0;
		}
		/*
		if (board[row - 1][col + 2] == 0 && (row - 1 >=0) && (col + 2 < 8)){
			board[row - 1][col + 2] = n;
			row1 = row - 1;
			col1 = col + 2;
		}
			
		else if ((board[row - 2][col + 1] == 0) && (row - 2 >= 0) && (col + 1 < 8) ){
			board[row - 2][col + 1] = n;
			row1 = row - 2;
			col1 = col + 1;
		}
		else if (board[row - 2][col - 1] == 0 && row-2 >= 0 && col - 1 >= 0){
			board[row - 2][col - 1] = n;
			row1 = row - 2;
			col1 = col - 1;
		}
		else if (board[row - 1][col - 2] == 0 && row - 1>=0 && col-2>=0){
			board[row - 1][col - 2] = n;
			row1 = row - 1;
			col1 = col - 2;
		} 
		else if (board[row + 1][col - 2] == 0 && row+1<8 && col-2>=0){
			board[row + 1][col - 2] = n;
			row1 = row + 1;
			col1 = col - 2;
		} 
		else if (board[row + 2][col - 1] == 0 && row+2 <8 && col-1>=0){
			board[row + 2][col - 1] = n;
			row1 = row + 2;
			col1 = col - 1;
		} 
		else if (board[row + 2][col + 1] == 0 && row+2<8 && col+1<8) {
			board[row + 2][col + 1] = n;
			row1 = row + 2;
			col1 = col + 1;
		} 
		else if (board[row + 1][col + 2] == 0 && row+1<8 && col+2<8) {
			board[row + 1][col + 2] = n;
			row1 = row + 1;
			col1 = col + 2;
		}
		system("cls");
		Print(N, M, board);
		Pause(1);

		// Рекурсивно проверяем, ведет ли это к решению.
		if (SearchMove((n + 1),row1,col1)) return 1;
		// Если мы дошли до этой строки, данное частичное решение
		// не приводит к полному.
		board[row1][col1] = 0;
		*/
		/*if (counter / 500 == 1){
			system("cls");
			Print(N, M, board);
			Pause(1);
		}*/

	}
	return 0;
}

int CheckBoard()
{
	int i, j;
	for (i = 0; i<N; i++)
	for (j = 0; j<M; j++)
		if (board[i][j] != 0)
			if (CheckKnight(i, j) == 0) return 0;
	return 1;
}
// Проверка определённого ферзя
int CheckKnight(int x, int y)
{
	//проверка возможных ходов
	//if ((board[x - 1][y + 2] == 0 && x-1>=0 && y+2<8) || (board[x - 2][y + 1] == 0 && x-2>0 && y+1<8) || (board[x - 2][y - 1] == 0 && x-2>=0 &&y-1>=0) || (board[x - 1][y - 2] == 0 && x-1>=0 && y-2>=0) || (board[x + 1][y - 2] == 0 && x+1<8 && y-2>=0) || (board[x + 2][y - 1] == 0 && x+2<8 && y-1>=0) || (board[x + 2][y + 1] == 0 && x+2<8 && y+1<8) || (board[x + 1][y + 2] == 0 && x+1<8 && y+2<8))
	if (board[x][y] != 1) 
	//if ((board[x][y + 2] == board[x][y] - 1 && x >= 0 && y + 2<8) || (board[x][y - 2] == board[x][y] - 1 && x >= 0 && y - 2<8) || (board[x - 2][y] == board[x][y] - 1 && x - 2 >= 0 && y >= 0) || (board[x + 2][y] == board[x][y] - 1 && x + 2 >= 0 && y >= 0) || (board[x][y + 1] == board[x][y] - 1 && x >= 0 && y + 1<8) || (board[x + 1][y + 1] == board[x][y] - 1 && x + 1 >= 0 && y + 1<8) || (board[x][y + 1] == board[x][y] - 1 && x >= 0 && y + 1<8) || (board[x + 1][y - 1] == board[x][y] - 1 && x + 1 >= 0 && y - 1<8) || (board[x][y - 1] == board[x][y] - 1 && x >= 0 && y - 1<8) || (board[x - 1][y - 1] == board[x][y] - 1 && x - 1 >= 0 && y - 1<8) || (board[x - 1][y] == board[x][y] - 1 && x - 1 >= 0 && y<8) || (board[x - 1][y + 1] == board[x][y] - 1 && x - 1 >= 0 && y + 1<8))
	if ((board[x][y] == board[x - 2][y + 1]+1 && x - 2>=0 && y + 1<8) || (board[x][y] == board[x - 1][y + 2]+1 && x - 1>=0 && y + 2<8) ||
		(board[x][y] == board[x + 1][y + 2]+1 && x + 1<8 && y + 2<8) || (board[x][y] == board[x + 2][y + 1]+1 && x + 2<8 && y + 1<8) ||
		(board[x][y] == board[x + 2][y - 1]+1 && x + 1<8 && y - 1 >=0) || (board[x][y] == board[x + 1][y - 2]+1 && x + 1<8 && y - 2>=0) ||
		((board[x][y] == board[x - 1][y - 2] + 1) && x - 1>=0 && y - 2>=0) || (board[x][y] == board[x - 2][y -1]+1 && x - 2>=0 && y -1 >=0))
		//return 1;
			return 1;
		else
	//return 0;
		return 0;
	else return 1;
}

int CheckKnightNew(int x, int y)
{
	if ((board[x - 2][y + 1]!=0 || x - 2 < 0 || y + 1>8) &&
		(board[x - 1][y + 2]!=0 || x - 1 < 0 || y + 2>8) &&
		(board[x + 1][y + 2]!=0 || x + 1>8 || y + 2>8) && 
		(board[x + 2][y + 1]!=0 || x + 2>8 || y + 1>8) &&
		(board[x + 2][y - 1]!=0 || x + 1>8 || y - 1 < 0) && 
		(board[x + 1][y - 2]!=0 || x + 1>8 || y - 2 < 0) &&
		(board[x - 1][y - 2]!=0 || x - 1 < 0 || y - 2 < 0) && 
		(board[x - 2][y - 1] !=0 || x - 2 < 0 || y - 1 < 0))
		//return 1;
		return 0;
	else
		//return 0;
		return 1;
}

void Zero(int n, int m, int a[N][M])
{
	int i, j;
	for (i = -3; i<n+3; i++)
	for (j = -3; j<m+3; j++)
		a[i][j] = -1;
	for (i = 0; i<n; i++)
	for (j = 0; j<m; j++)
		a[i][j] = 0;
}


// Выводим доску на экран
void Print(int n, int m, int a[N][M])
{
	int i, j;
	for (i = 0; i<n; i++){
		for (j = 0; j<m; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}

void Pause(int key)
{
	if (key == 1) getchar(); else for (int i = 0; i<100000000; i++);
}


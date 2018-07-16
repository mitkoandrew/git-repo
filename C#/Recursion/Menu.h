#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Math.h>
#include <Time.h>
#include <string.h>
#include "01_Binary.h"
#include "02_Exponentation.h"
#include "03_Calculator_3_to_20.h"
#include "04_Count_Route.h"
#include "05_Chess_Move.h"

void task_1();
void task_2();
void task_3();
void task_4();
void task_5();


void Menu()
{
	int sel;
	do
	{
		//1.	����������� ������� �������� �� 10 ������� � �������� ��������� ��������.
		printf("1-from decimal to binary)\n");
		/*2.	����������� ������� ���������� ����� a � ������� b :
		a.��� ��������;
		b.����������;
		c.	*����������, ��������� �������� �������� �������.
		*/
		printf("2-a^b\n");
		/*3.	����������� ����������� ����������� ����� �����, ���������� �� ������.� ����������� ��� �������, ������ ������� �������� ����� :
		1. ������� 1
			2. ������ �� 2

			������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� ����� � 2 ����.������� ���������� ��������, ������� ����� 3 ����������� � ����� 20.
			�) � �������������� �������;
		�) � �������������� ��������.
		*/
		printf("3-calculate how many program exist to perform 3 to 20\n");
		/*4.	*���������� ��������� � �������������. ����������� ������ ������� � ������������ � ���������� ���������� ���������.

�������� �����:
3 3
1 1 1
0 1 0
0 1 0
*/
		printf("4-find a way\n");
		/*5.	***��������� ������ ���� ��������� ����� �������� NxM, ������ ����� ��� ���� ����� �� ������ ����. ����� �������� ������� ����� �� ��� � � ������ � 8 ������. ������� ������ � �������� ��������� ����.*/
		printf("5-a way for a Knight\n");
		printf("0-exit\n");
		scanf_s("%d", &sel);
		switch (sel)
		{
		case 1:task_1();
			break;
		case 2:task_2();
			break;
		case 3:task_3();
			break;
		case 4:task_4();
			break;
		case 5:task_5();
			break;
		case 0:printf("Bye-bye\n");
			break;
		default:
			printf("Wrong selected\n");
			break;
		}
	} while (sel != 0);
	//system("pause");
}

void task_1() {
	int value = 0;
	printf("type a decimal value to perform in binary code:\n");
	scanf("%d", &value);
	printf("binary notation: \n");
	decimalToBinary(value);
	printf("\n\n");
}

void task_2(){
	int a, b;
	printf("exponenation a^b \n");
	printf("type a:\n");
	scanf("%d", &a);	
	printf("type b:\n");
	scanf("%d", &b);
	printf("classical a^b = %d\n", classicPower(a,b));
	printf("recursion a^b = %d\n", recursionPower(a, b));
	printf("recursion modern a^b = %d\n", recursionPowerModern(a, b));
	printf("\n");
	//printf("recursion modern a^b = %d\n", Pow(a, b));
}
void task_3(){
	printf("you can reach 20 from 3 by %d methods (array)\n", arrayCalculator(3, 20));
	printf("you can reach 20 from 3 by %d methods (recursion)\n", recursiveCalculator(3, 20));
	printf("\n");	
}
void task_4(){
	FILE *in;
	int n, m, data;
	int map[3][3];
	in = fopen("C:\\GAMES\\GB\\HW_L7\\HW_L7\\HW_L7\\map.txt", "r");
	if (in == NULL){
		puts("Can't read file");
	}
	fscanf(in, "%d", &n);
	fscanf(in, "%d", &m);
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		fscanf(in, "%d", &map[i][j]);
	}
	fclose(in);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%4d ", map[i][j]);
		printf("\n");
	}
	//printf("a count of possible routes is %d\n", countRoute(n, m, map));
	printf("a count of possible routes is %d\n", countRouteRecursive(n - 1, m - 1, map));
	printf("\n");
}
void task_5(){
	moveKnight();
}
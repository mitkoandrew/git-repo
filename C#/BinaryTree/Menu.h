#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Math.h>
#include <Time.h>
#include <string.h>
#include "01_HashFunction.h"
#include "02_BinarySarchTree.h"

void task_1();
void task_2();
void task_3();


void Menu()
{
	int sel;
	do
	{
		//1.	Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
		printf("1-hash-function\n");
		/*2.	Переписать программу, реализующее двоичное дерево поиска. 
			*а) Добавить в него обход дерева различными способами;
			*б) Реализовать поиск в двоичном дереве поиска;
			*в) *Добавить в программу обработку командной строки с помощью которой можно указывать из какого файла считывать данные, каким образом обходить дерево.

		*/
		printf("2-binary tree\n");
		/*3.	3.	*Разработать базу данных студентов из двух полей “Имя”, “Возраст”, “Табельный номер” в которой использовать все знания, полученные на уроках.
		*Считайте данные в двоичное дерево поиска. Реализуйте поиск по какому-нибудь полю базы данных (возраст, вес)	
		*/
		printf("0-exit\n");
		scanf_s("%d", &sel);
		switch (sel)
		{
		case 1:task_1();
			break;
		case 2:task_2();
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
	int strMaxSize = 100;
	char *array = (char *)malloc(strMaxSize*sizeof(char)+10);
	if ((array == NULL))
	{
		puts("Can't allocated memory");
	}
	printf("type a string:\n");
	scanf("%s", array);
	_flushall();
	printf("%d\n",hashFunction(array));
	printf("\n\n");
}

void task_2(){
	printf("\n");
	binarySearchTree();
	printf("\n");
}
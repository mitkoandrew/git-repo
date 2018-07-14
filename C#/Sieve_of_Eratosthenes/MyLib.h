#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void Init(int n, int *a){
	a[0] = 0;
	a[1] = 1;
	for (int i = 0; i < n; i++){
		a[i] = i + 2;//начинается массив с двойки
	}
}

void Print1D(int n, int *a){
	for (int i = 0; i < n; i++){
		printf("%4d", a[i]);
	}
	printf("\n");
}

void Sieve(int elem, int n, int* a) {
	//for (int i = ind; i < n; i++){
	//	if (a[i] % elem == 0)
	//		a[i] = 0;
	if (elem == 2) {
		for (int i = elem *elem-2; i < n; i += (elem)){
			a[i] = 0;
		}
	}
	else{
		for (int i = elem *elem-2; i < n; i += (2*elem)){//для нечетных чисел
			a[i] = 0;
		}
	}
//	Print1D(n, a);
}

void PrintToFile(int n, int *a){
	FILE *out;
	out = fopen("C:\\GAMES\\GB\\HW_L4\\HW_L4\\Sieve_of_Eratosthenes\\primes.txt", "w");
	if (out == NULL){
		puts("Can't write file");
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != 0)
			fprintf(out, "%4d ", a[i]);
	}
	fclose(out);
	puts("Done!");
}
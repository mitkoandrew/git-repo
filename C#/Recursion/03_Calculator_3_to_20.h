#pragma once
#include <stdio.h>
#include <stdlib.h>

int recursiveCalculator(int q, int p){
	if (p < q) return 0;
	if (p == q) return 1;
	if (p > q) {
		if (p % 2 == 0)	
			return recursiveCalculator(q, p - 1) + recursiveCalculator(q, p / 2);
		else return recursiveCalculator(q, p - 1);
	}
}

int arrayCalculator(int q, int p){
	int array[30];
	array[0] = 0;
	array[1] = 0;
	array[2] = 0;
	array[3] = 1;//1 операция на тройку
	for (int i = q + 1; i <= p; i++){
		if ((i % 2 == 0) && (i > 5))
			array[i] = array[i - 1] + array[i / 2];
		else
			array[i] = array[i-1];

	}
	return array[p];
}
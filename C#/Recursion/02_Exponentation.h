#pragma once
#include <stdio.h>
#include <stdlib.h>

long classicPower(int a, int b){
	long result = 1;
	for (int i = 0; i < b; i++)
		result = result * a;
	return result;
}

long recursionPower(int a, int b){
	if (b == 0) return 1;
	else return recursionPower(a, b - 1) * a;
}

long recursionPowerModern(int a, int b){
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b == 2) return a * a;
	//if (b % 2 == 0) return recursionPowerModern(a, b / 2) * a *(a* recursionPowerModern(a, b % 2));
	//else return recursionPowerModern(a, b / 2) * a * recursionPowerModern(a, b % 2);
	//return recursionPowerModern(recursionPowerModern(a, b % 2), b / 2);
	return (recursionPowerModern(a, b / 2) * recursionPowerModern(a, b / 2))  * recursionPowerModern(a, b % 2);
	//такая формула получилась
}

long Pow(int a, int b)//a^b
{
	long n = 1, s = a, k = b;
	while (k != 0) {
		if (k % 2 == 0)
		{
			s = s*s; k /= 2;
		}
		else
		{
			k--;
			n = n*s;
		}
	}
	return n;
}

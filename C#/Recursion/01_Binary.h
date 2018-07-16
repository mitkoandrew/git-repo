#pragma once
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int value){
	if (value != 0) {
		decimalToBinary(value / 2);
		printf("%d",value % 2);
	}
}
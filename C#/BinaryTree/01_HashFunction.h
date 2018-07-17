#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>

int hashFunction(char* array){
	int result = 0;
	for (int i = 0; i < strlen(array); i++){
		result = result + array[i];
	}
	return result;
}
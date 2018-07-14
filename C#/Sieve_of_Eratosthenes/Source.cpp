#define _CRT_SECURE_NO_WARNINGS
#include "MyLib.h"
#define N 100
//program by Andrew Mitko 11.06.2017
//tyler87@inbox.ru

int main()
{
	int a[N];
	int k;
	int i = 0;
	Init(N,a);
	Print1D(N, a);
	k = a[i];
	//while (i < N)
	while (k*k < N)
	{
		k = a[i];
		if (k == 0) {
			i++;
			continue;
		}
		Sieve(k, N, a);
		i++;
	}
	Print1D(N, a);
	PrintToFile(N, a);
	getchar();
	return 0;
}
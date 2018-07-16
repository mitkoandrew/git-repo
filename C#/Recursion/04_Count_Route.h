#pragma once
#include <stdio.h>
#include <stdlib.h>

//нерекурсивный способ
int countRoute(int n, int m, int map[3][3]){
	int i, j;
	for (j = 0; j < m; j++) {
		if (map[0][j] == 1) map[0][j] = 1;
		for (i = 1; i < n; i++)
		{
			if (map[i][0] == 1)
				map[i][0] = 1;
			for (j = 1; j < m; j++){
				if (map[i][j] == 1)
					map[i][j] = map[i][j - 1] + map[i - 1][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%4d ", map[i][j]);
		printf("\n");
	}
	return map[n-1][m-1];
}

//с рекурсией
int countRouteRecursive(int n, int m, int map[3][3]){
	/*if (n == 0) return 1; 
	if (m == 0) return 1;
	if (n > 0 && m > 0)
	return countRouteRecursive(n - 1, m, map) +countRouteRecursive(n, m - 1, map);
	*/
	if (n == 0 && map[n][m] == 1) return 1;
	if (m == 0 && map[n][m] == 1) return 1;
	if (map[n][m] == 1)
		return countRouteRecursive(n - 1, m, map) + countRouteRecursive(n, m - 1, map);
	else return 0;
}
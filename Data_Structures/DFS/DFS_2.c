#include <stdio.h>
#pragma warning (disable : 4996)
#define SIZE 8

int a[SIZE + 1][SIZE + 1] ={
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 1, 0, 0, 0, 0, 0, 0},
   {0, 1, 0, 1, 1, 0, 0, 0, 0},
   {0, 0, 1, 0, 0, 0, 0, 1, 0},
   {0, 0, 1, 0, 0, 1, 0, 0, 0},
   {0, 0, 0, 0, 1, 0, 1, 0, 0},
   {0, 0, 0, 0, 0, 1, 0, 1, 1},
   {0, 0, 0, 1, 0, 0, 1, 0, 1},
   {0, 0, 0, 0, 0, 0, 1, 1, 0},
};
int v[SIZE + 1];

void DFS(int i) {
	v[i] = i;
	for (int j = i; j < SIZE + 1; j++) {
		if (a[i][j] == 1 && !v[j]) {
			printf("%d->%d\n", i, j);
			DFS(j);
		}
	}
}

int main() {
	for (int i = 1; i < SIZE+1; i++)
	{
		printf("===============\n");
		DFS(i);
	}
	return 0;
}


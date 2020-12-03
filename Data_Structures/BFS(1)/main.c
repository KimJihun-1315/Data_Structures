#include <stdio.h>

#define SIZE 8
int map[SIZE + 1][SIZE + 1] =
{
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 1, 0, 0, 0, 0, 0, 0},
   {0, 1, 0, 1, 1, 0, 0, 0, 0},
   {0, 0, 1, 0, 0, 0, 0, 1, 0},
   {0, 0, 1, 0, 0, 1, 0, 0, 0},
   {0, 0, 0, 0, 1, 0, 1, 0, 0},
   {0, 0, 0, 0, 0, 1, 0, 1, 1},
   {0, 0, 0, 1, 0, 0, 1, 0, 1},
   {0, 0, 0, 0, 0, 0, 1, 1, 0}
};

int visited[SIZE + 1];
int queue[100];
int front = 0, back = 0;
int main() {
	int startV = 1;
	visited[startV] = 1;
	queue[back++] = startV;
	int row;//За
	while (front != back) {
		row = queue[front++];
		for (int i = 1; i < SIZE; i++) {
			if (map[row][i] == 1 && visited[i] == 0) {
				printf("%d->%d\n", row, i);
				queue[back++] = i;
				visited[i] = i;
			}
		}
	}
}
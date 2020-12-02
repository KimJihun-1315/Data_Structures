#pragma warning (disable : 4996)
#include <stdio.h>
//DFS(깊이 우선탐색)(
int n;
int map[31][31];	//인접행렬
int visited[31];	//방문여부

void DFS(int v) {
	visited[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (map[v][i] == 1 && !visited[i]) {
			printf("%d->%d로 이동\n", v, i);
			DFS(i);
		}
	}
}

int main() {
	int startV;
	int v1, v2;
	scanf("%d", &n);
	scanf("%d", &startV);
	while (1) {
		scanf("%d %d", &v1, &v2);
		if (v1 == -1 && v2 == -1)
			break;
		map[v1][v2] = map[v2][v1] = 1;
	}
	DFS(startV);
	return 0;
}

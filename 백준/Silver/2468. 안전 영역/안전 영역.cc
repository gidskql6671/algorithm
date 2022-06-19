#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101

int N, Count, count_max, H;
int map[MAX][MAX];
bool check[MAX][MAX];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	if (!check[x][y] && map[x][y] > H) {
		check[x][y] = true;
		q.push(make_pair(x, y));
		Count++;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
				if (!check[nx][ny] && map[nx][ny] > H) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	int max = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			if (max < map[i][j])
				max = map[i][j];
		}

	for (; H <= max; H++) {
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++) {
				if (check[i][j]) continue;
				if (map[i][j] <= H) continue;
				bfs(i, j);
			}
		
		if (count_max < Count)
			count_max = Count;
		Count = 0;
		memset(check, 0, sizeof(check));
	}

	printf("%d\n", count_max);

	return 0;
}
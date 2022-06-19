#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101

int height, width;
int map[MAX][MAX];
int check[MAX][MAX];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	check[x][y] = 1;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		if (x == width && y == height) {
			printf("%d\n", check[x][y]);
			break;
		}

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (1 <= nx && nx <= width && 1 <= ny && ny <= height) {
				if (!check[nx][ny] && map[nx][ny] == 1) {
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	
	cin >> height >> width;

	for (int i = 1; i <= height; i++) 
		for (int j = 1; j <= width; j++)
			scanf("%1d", &map[j][i]);

	bfs(1, 1);

	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int map[21][21] = { 0 };
bool visit[21][21] = { 0 };
bool alpha_visit[26] = { 0 };

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int COUNT;
int COUNT_MAX;
int h, w;

void dfs(int x, int y) {
	COUNT++;
	visit[y][x] = true;
	alpha_visit[map[y][x]- 65] = true;
		
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= w && ny >= 1 && ny <= h) {
			if (!alpha_visit[map[ny][nx]-65] && !visit[ny][nx]) {
				alpha_visit[map[ny][nx]-65] = true;
				visit[ny][nx] = true;
				dfs(nx, ny);
			}
		}
	}
	if (COUNT > COUNT_MAX)
		COUNT_MAX = COUNT;
	COUNT--;
	alpha_visit[map[y][x]-65] = false;
	visit[y][x] = false;
}

int main() {
	
	scanf("%d %d\n", &h, &w);

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			map[i][j] = getchar();
		}
		getchar();
	}

	dfs(1, 1);

	printf("%d\n",COUNT_MAX);

	return 0;
}
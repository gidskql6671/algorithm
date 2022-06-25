#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[1000][1000];
queue<pair<int, int>> q;
int visit[1000][1000];
int n, m;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (visit[ny][nx] == -1 && arr[ny][nx] == 0) {
					q.push(make_pair(nx, ny));
					visit[ny][nx] = visit[y][x] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> m >> n;

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
				q.push(make_pair(j, i));
			else
				visit[i][j] = -1;
		}

	bfs();

	int Day = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && visit[i][j] == -1) {
				puts("-1");
				return 0;
			}
			Day = max(Day, visit[i][j]);
		}
	}
	printf("%d\n", Day);

	return 0;
}
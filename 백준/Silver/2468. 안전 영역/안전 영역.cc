#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int n;
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};
int board[101][101];

bool isInside(int y, int x) {
  return 0 <= y and y < n and 0 <= x and x < n;
}

void bfs(bool visited[101][101], int sy, int sx, int height) {
  queue<pair<int, int>> q;
  q.push({sy, sx});
  visited[sy][sx] = true;

  while(not q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (isInside(ny, nx) and board[ny][nx] > height and not visited[ny][nx]) {
        q.push({ny, nx});
        visited[ny][nx] = true;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);



  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  int result = 1;
  for(int height = 1; height < 100; height++) {
    int count = 0;
    bool visited[101][101] = {{ 0 }};
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if (board[i][j] > height and not visited[i][j]) {
          count++;
          bfs(visited, i, j, height);
        }
      }
    }

    result = max(result, count);
  }

  cout << result << endl;

  return 0;
}

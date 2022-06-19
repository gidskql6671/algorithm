#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int n, m;
bool board[51][51];

bool isInside(int y, int x) {
  return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs(bool visited[][51], int startY, int startX) {
  queue<pair<int, int>> q;

  q.push({startY, startX});
  visited[0][0] = true;
  while(!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for(int i = 0; i < 8; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if (isInside(ny, nx) && !visited[ny][nx] && board[ny][nx] == 1) {
        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  while(true) {
    cin >> m >> n;
    if (m == 0 && n == 0) {
      return 0;
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> board[i][j];
      }
    }

    int count = 0;
    bool visited[51][51] = { 0 };
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if (board[i][j] == 1 && !visited[i][j]) {
          count++;
          bfs(visited, i, j);
        }
      }
    }

    cout << count << "\n";
  }

  return 0;
}

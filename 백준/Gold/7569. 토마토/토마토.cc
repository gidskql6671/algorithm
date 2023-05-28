#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n, m, h;
int board[101][101][101];

int dz[] = {-1, 0, 0, 0, 0, 1};
int dy[] = {0, -1, 0, 1, 0, 0};
int dx[] = {0, 0, 1, 0, -1, 0};


bool isInside(int nz, int ny, int nx) {
  return 0 <= nz and nz < h and 0 <= ny and ny < n and 0 <= nx and nx < m;
}

int bfs() {
  queue<pair<tuple<int, int, int>, int>> q;

  for(int k = 0; k < h; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if (board[k][i][j] == 1) {
          q.push({{k, i, j}, 0});
        }
      }
    }
  }

  int maxDistance = 0;
  while(not q.empty()) {
    int z, y, x;
    tie(z, y, x) = q.front().first;
    int distance = q.front().second;
    q.pop();

    maxDistance = max(maxDistance, distance);

    for(int i = 0; i < 6; i++) {
      int nz = z + dz[i];
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (isInside(nz, ny, nx) and board[nz][ny][nx] == 0) {
        board[nz][ny][nx] = 1;
        q.push({{nz, ny, nx}, distance + 1});
      }
    }
  }

  for(int k = 0; k < h; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if (board[k][i][j] == 0) {
          return -1;
        }
      }
    }
  }

  return maxDistance;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> m >> n >> h;
  for(int k = 0; k < h; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
          cin >> board[k][i][j];
      }
    }
  }

  cout << bfs() << endl;

  return 0;
}

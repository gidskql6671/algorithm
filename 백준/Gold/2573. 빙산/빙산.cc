#include <bits/stdc++.h>
#define INF 987654321012L
typedef long long ll;
using namespace std;


int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n, m;
int board[300][300], tmp[300][300];

bool isInside(int y, int x) {
  return 0 <= y and y < n and 0 <= x and x < m;
}

void hitIce() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (board[i][j] == 0) {
        tmp[i][j] = 0;
      }
      else {
        int nearIceCount = 0;
        for(int k = 0; k < 4; k++) {
          int ny = i + dy[k];
          int nx = j + dx[k];

          if (isInside(ny, nx) and board[ny][nx] == 0) {
            nearIceCount++;
          }
        }

        tmp[i][j] = max(0, board[i][j] - nearIceCount);
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      board[i][j] = tmp[i][j];
    }
  }
}

void bfs(int sy, int sx, bool visited[300][300]) {
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

      if (isInside(ny, nx) and board[ny][nx] > 0 and not visited[ny][nx]) {
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


  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  int count = 0;
  bool isDivided = false;
  while(true) {
    count++;

    hitIce();

    bool visited[300][300] = {false};
    int groupCount = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if (board[i][j] != 0 and not visited[i][j]) {
          groupCount++;

          bfs(i, j, visited);
        }
      }
    }

    if (groupCount == 0) {
      break;
    }
    else if (groupCount >= 2) {
      isDivided = true;
      break;
    }
  }

  if (isDivided) {
    cout << count << endl;
  }
  else {
    cout << 0 << endl;
  }

  return 0;
}

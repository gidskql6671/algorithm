#include <bits/stdc++.h>
#define INF 987654321012L
typedef long long ll;
using namespace std;


int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char board[12][6];

bool isInside(int y, int x) {
  return 0 <= y and y < 12 and 0 <= x and x < 6;
}

bool bfs(int sy, int sx, bool visited[12][6]) {
  queue<pair<int, int>> q, deletedQueue;
  char targetPuyo = board[sy][sx];

  q.push({sy, sx});
  visited[sy][sx] = true;

  while(not q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    deletedQueue.push({y, x});

    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (isInside(ny, nx) and board[ny][nx] == targetPuyo and not visited[ny][nx]) {
        q.push({ny, nx});
        visited[ny][nx] = true;
      }
    }
  }

  if (deletedQueue.size() >= 4) {
    while(not deletedQueue.empty()) {
      int y = deletedQueue.front().first;
      int x = deletedQueue.front().second;
      deletedQueue.pop();

      board[y][x] = '.';
    }

    return true;
  }

  return false;
}

bool boom() {
  bool visited[12][6] = {false};
  bool isBoom = false;

  for(int i = 0; i < 12; i++) {
    for(int j = 0; j < 6; j++) {
      if (board[i][j] != '.' and not visited[i][j]) {
        bool isDeleted = bfs(i, j, visited);

        if (isDeleted) {
          isBoom = true;
        }
      }
    }
  }

  return isBoom;
}

void applyGravity() {
  for(int x = 0; x < 6; x++) {
    for(int y = 11; y > 0; y--) {
      for(int i = 0; i < y; i++) {
        if (board[i][x] == '.') {
          board[i][x] = board[i + 1][x];
          board[i + 1][x] = '.';
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  for(int i = 11; i >= 0; i--) {
    for(int j = 0; j < 6; j++) {
      cin >> board[i][j];
    }
  }

  int count = 0;
  while(true) {
    bool isBoom = boom();
    if (not isBoom) {
      break;
    }

    applyGravity();

    count++;
  }

  cout << count << endl;

  return 0;
}

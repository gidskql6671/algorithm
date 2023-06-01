#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


char board[12][12], newBoard[12][12];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  for(int i = 0; i < 12; i++) {
    for(int j = 0; j < 12; j++) {
      board[i][j] = '.';
      newBoard[i][j] = '.';
    }
  }

  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> board[i][j];
    }
  }

  int minY = INF, minX = INF, maxY = -INF, maxX = -INF;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if (board[i][j] == 'X') {
        int seaCount = 0;
        for(int k = 0; k < 4; k++) {
          int ny = i + dy[k];
          int nx = j + dx[k];

          if (board[ny][nx] == '.') {
            seaCount++;
          }
        }

        if (seaCount < 3) {
          newBoard[i][j] = 'X';

          minY = min(minY, i);
          minX = min(minX, j);
          maxY = max(maxY, i);
          maxX = max(maxX, j);
        }
      }
    }
  }

  for(int i = minY; i <= maxY; i++) {
    for(int j = minX; j <= maxX; j++) {
      cout << newBoard[i][j];
    }
    cout << "\n";
  }

  return 0;
}

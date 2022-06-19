#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1};

int n, m;
int board[501][501];
int dp[501][501];

bool isInside(int y, int x) {
  return 0 <= y && y < n && 0 <= x && x < m;
}

int dfs(int curY, int curX) {
  if (dp[curY][curX] != -1) {
    return dp[curY][curX];
  }

  int result = 0;
  for(int i = 0; i < 4; i++) {
    int ny = curY + dy[i];
    int nx = curX + dx[i];

    if (isInside(ny, nx) && board[ny][nx] < board[curY][curX]) {
      result += dfs(ny, nx);
    }
  }

  dp[curY][curX] = result;
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      dp[i][j] = -1;
    }
  }

  dp[n-1][m-1] = 1;
  cout << dfs(0, 0) << endl;

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int dirs[6][4][4] = {
  {},
  {{0}, {1}, {2}, {3}},
  {{0, 2}, {1, 3}},
  {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
  {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
  {{0, 1, 2, 3}}
};

int n, m, cctvCount;
int board[8][8];
vector<pair<int, int>> cctvs;
int minResult = INF;

bool isInside(int y, int x) {
  return 0 <= y and y < n and 0 <= x and x < m;
}

int getCctvDirCount(int cctv) {
  switch (cctv) {
  case 1: case 3: case 4:
    return 4;
  case 2:
    return 2;
  case 5:
    return 1;
  }

  return -1;
}

int getCctvDirCountOf1Case(int cctv) {
  switch (cctv) {
  case 1:
    return 1;
  case 2: case 3:
    return 2;
  case 4:
    return 3;
  case 5:
    return 4;
  }

  return -1;
}

int calculate(vector<int> &cctvDirs) {
  bool viewed[8][8] = { false };

  for(int i = 0; i < cctvCount; i++) {
    int y = cctvs[i].first;
    int x = cctvs[i].second;
    int cctvDir = cctvDirs[i];

    int cctv = board[y][x];
    int cctvDirCount = getCctvDirCountOf1Case(cctv);

    for(int j = 0; j < cctvDirCount; j++) {
      int dir = dirs[cctv][cctvDir][j];
      y = cctvs[i].first;
      x = cctvs[i].second;

      while(true) {
        viewed[y][x] = true;

        y += dy[dir];
        x += dx[dir];

        if (not isInside(y, x) or board[y][x] == 6) {
          break;
        }
      }
    }
  }

  int count = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (board[i][j] == 0 and not viewed[i][j]) {
        count++;
      }
    }
  }

  return count;
}

void recur(int curCctvIdx, vector<int> &cctvDirs) {
  if (curCctvIdx == cctvCount) {
    minResult = min(minResult, calculate(cctvDirs));
    return;
  }

  pair<int, int> cctv = cctvs[curCctvIdx];
  int curCctv = board[cctv.first][cctv.second];
  int curCctvDirCount = getCctvDirCount(curCctv);

  for(int i = 0; i < curCctvDirCount; i++) {
    cctvDirs[curCctvIdx] = i;
    recur(curCctvIdx + 1, cctvDirs);
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

      if (1 <= board[i][j] and board[i][j] <= 5) {
        cctvs.push_back({i, j});
      }
    }
  }

  cctvCount = cctvs.size();
  vector<int> cctvDirs = vector<int>(cctvCount, 0);
  recur(0, cctvDirs);

  cout << minResult << endl;

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

bool isCPCU1202(vector<vector<int>> before, vector<vector<int>> after);
bool isInside(int y, int x, int n, int m);
bool bfs(vector<vector<int>> before, set<pair<int, int>> changedPositions);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> before(n, vector<int>(m)), after(n, vector<int>(m));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> before[i][j];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> after[i][j];
    }
  }

  cout << (isCPCU1202(before, after) ? "YES" : "NO") << endl;

  return 0;
}

bool isCPCU1202(vector<vector<int>> before, vector<vector<int>> after) {
  // 1. 완전히 동일하다면, YES
  // 2. 변경된 영역의 before와 after의 영역이 같고 나머지 부분은 동일한 값이라면, YES
  int n = before.size();
  int m = before[0].size();

  set<pair<int, int>> changedPositions;
  int changedVal = -1;
  bool isChanged = false;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (before[i][j] != after[i][j]) {
        if (changedVal == -1) {
          changedVal = after[i][j];
          isChanged = true;
          changedPositions.insert({i, j});
        }
        else if (changedVal == after[i][j]) {
          changedPositions.insert({i, j});
        }
        else {
          return false;
        }
      }
    }
  }

  if (!isChanged) {
    return true;
  }

  return bfs(before, changedPositions);
}

bool isInside(int y, int x, int n, int m) {
  return 0 <= y && y < n && 0 <= x && x < m;
}

bool bfs(vector<vector<int>> before, set<pair<int, int>> changedPositions){
  int n = before.size(), m = before[0].size();
  queue<pair<int, int>> q;
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  pair<int, int> startPos = *changedPositions.begin();
  q.push(startPos);
  visited[startPos.first][startPos.second] = true;

  while(!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    int val = before[y][x];
    q.pop();

    if (changedPositions.count({y, x}) == 0) {
      return false;
    }
    changedPositions.erase({y, x});

    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (isInside(ny, nx, n, m) && !visited[ny][nx] && val == before[ny][nx]) {
        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }

  if (changedPositions.size() > 0) {
    return false;
  }

  return true;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n;
int board[100][100];
bool visited[100][100];
int totalMin = INF, totalMax = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isInside(int y, int x, int n) {
  return 0 <= y && y < n && 0 <= x && x < n;
}

bool bfs(int diff) {
  queue<pair<int, int>> q;

  // [totalMin, totalMin + diff], [totalMin + 1, totalMin + 1 + diff], ..., [totalMax, totalMax + diff]
  // 최소 값(minVal)과 범위(diff)를 사용해 해당 영역에 포함되는 구역만 지나가면서 도착지점에 갈 수 있는지 체크
  for(int minVal = totalMin; minVal <= totalMax; minVal++) {

    // [minVal, minVal + diff]에 속해야 지나갈 수 있다.
    memset(visited, true, sizeof(visited));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if (minVal <= board[i][j] && board[i][j] <= minVal + diff) {
          visited[i][j] = false;
        }
      }
    }

    if (!visited[0][0]) {
      q.push({0, 0});
      visited[0][0] = true;
    }

    while(!q.empty()) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();

      if (y == n - 1 && x == n - 1) {
        return true;
      }

      for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (isInside(ny, nx, n) && !visited[ny][nx]) {
          q.push({ny, nx});
          visited[ny][nx] = true;
        }
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];

      totalMin = min(totalMin, board[i][j]);
      totalMax = max(totalMax, board[i][j]);
    }
  }

  int start = 0;
  int end = totalMax - totalMin;

  // 이분 탐색을 사용하는 알고리즘
  // 주어진 max - min의 차이 내에서 도착지점으로 갈 수 있다면 차이를 더 줄임
  // 가지 못한다면 차이를 넓힘.
  while(start <= end) {
    int mid = (start + end) / 2;

    if (bfs(mid)) {
      end = mid - 1;
    }
    else {
      start = mid + 1;
    }
  }

  cout << end + 1 << endl;

  return 0;
}
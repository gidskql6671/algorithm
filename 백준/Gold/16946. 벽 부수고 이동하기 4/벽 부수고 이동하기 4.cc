#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int n, m;
int board[1001][1001], visited[1001][1001];
int sizeOfArea[1000000];
int countOfArea = 0;

bool isInside(int y, int x) {
  return 0 <= y and y < n and 0 <= x and x < m;
}

int bfs(int sy, int sx) {
  int count = 0;
  queue<pair<int, int>> q;

  q.push({sy, sx});
  visited[sy][sx] = countOfArea;
  count++;

  while(not q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (isInside(ny, nx) and board[ny][nx] == 0 and visited[ny][nx] == -1) {
        count++;

        q.push({ny, nx});
        visited[ny][nx] = countOfArea;
      }
    }
  }

  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    string line;
    cin >> line;

    for(int j = 0; j < m; j++) {
      board[i][j] = line[j] - '0';
      visited[i][j] = -1;
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (board[i][j] == 0 and visited[i][j] == -1) {
        sizeOfArea[countOfArea++] = bfs(i, j);
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (board[i][j] == 1) {
        set<int> areas;
        for(int k = 0; k < 4; k++) {
          int ny = i + dy[k];
          int nx = j + dx[k];

          if (isInside(ny, nx) and board[ny][nx] == 0) {
            areas.insert(visited[ny][nx]);
          }
        }

        int count = 1;
        for(int area : areas) {
          count += sizeOfArea[area];
        }

        cout << (count % 10);
      }
      else {
        cout << 0;
      }
    }
    cout << "\n";
  }

  return 0;
}

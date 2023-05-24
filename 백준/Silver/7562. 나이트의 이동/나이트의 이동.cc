#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n;
bool visited[301][301];
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool isInside(int y, int x) {
  return 0 <= y and y < n and 0 <= x and x < n;
}

int bfs(pair<int, int> start, pair<int, int> target) {
  queue<pair<pair<int,int>, int>> q;
  q.push({start, 0});
  visited[start.first][start.second] = true;

  while(!q.empty()) {
    int cy = q.front().first.first;
    int cx = q.front().first.second;
    int distance = q.front().second;
    q.pop();

    if (cy == target.first and cx == target.second) {
      return distance;
    }

    for(int i = 0; i < 8; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if (isInside(ny, nx) and not visited[ny][nx]) {
        visited[ny][nx] = true;
        q.push({{ny, nx}, distance + 1});
      }
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;

  while(T--) {
    pair<int, int> cur, target;
    cin >> n >> cur.first >> cur.second >> target.first >> target.second;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        visited[i][j] = false;
      }
    }

    cout << bfs(cur, target) << "\n";
  }

  return 0;
}

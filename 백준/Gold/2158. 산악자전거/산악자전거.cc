#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


struct Node {
  double time;
  double speed;
  int y;
  int x;
};

struct Comp {
  bool operator()(Node a, Node b) {
    if (a.time != b.time) {
      return a.time > b.time;
    }
    if (a.speed != b.speed) {
      return a.speed < b.speed;
    }
    if (a.y != b.y) {
      return a.y < b.y;
    }
    return a.x < b.x;
  }
};

int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};
int v, n, m;
int board[100][100];
double visited[100][100][2];

bool isInside(int y, int x) {
  return 0 <= y and y < n and 0 <= x and x < m;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> v >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
      visited[i][j][0] = INF;
      visited[i][j][1] = -1;
    }
  }

  priority_queue<Node, vector<Node>, Comp> pq;

  pq.push(Node{0, (double)v, 0, 0});

  while(not pq.empty()) {
    double time = pq.top().time;
    double speed = pq.top().speed;
    int y = pq.top().y;
    int x = pq.top().x;
    pq.pop();

    if (y == n - 1 and x == m - 1) {
      cout << time << endl;
      break;
    }

    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (isInside(ny, nx)) {
        double nTime = time + (1 / speed);
        double nSpeed = speed * pow(2, board[y][x] - board[ny][nx]);
        if (visited[ny][nx][0] <= nTime and visited[ny][nx][1] >= nSpeed) {
          continue;
        }

        pq.push(Node{nTime, nSpeed, ny, nx});
        visited[ny][nx][0] = nTime;
        visited[ny][nx][1] = nSpeed;
      }
    }
  }

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int board[101];
bool visited[101];

int bfs() {
  queue<pair<int, int>> q;
  q.push({1, 0});
  visited[1] = true;

  while(not q.empty()) {
    int cur = q.front().first;
    int round = q.front().second;
    q.pop();

    for(int i = 1; i <= 6; i++) {
      int next = cur + i;
      int nextRound = round + 1;

      if (next == 100) {
        return nextRound;
      }

      if (board[next] > 0) {
        visited[next] = true;
        next = board[next];
      }

      if (not visited[next]) {
        visited[next] = true;
        q.push({next, nextRound});
      }
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n + m; i++) {
    int tail, head;
    cin >> tail >> head;

    board[tail] = head;
  }

  cout << bfs() << endl;

  return 0;
}

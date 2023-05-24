#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n, m, r, cnt = 1;
int visited[100001];
vector<vector<int>> graph(100001);

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = cnt++;

  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    for(int next : graph[cur]) {
      if (!visited[next]) {
        visited[next] = cnt++;
        q.push(next);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> m >> r;
  for(int i = 0; i < m; i++) {
    int tail, head;
    cin >> tail >> head;

    graph[tail].push_back(head);
    graph[head].push_back(tail);
  }

  for(int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  bfs(r);

  for(int i = 1; i <= n; i++) {
    cout << visited[i] << "\n";
  }

  return 0;
}

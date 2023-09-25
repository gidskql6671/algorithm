#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


vector<vector<int>> graph;

void dfs(int cur, vector<bool> &visited) {
  visited[cur] = true;
  cout << cur << " ";

  for(int next : graph[cur]) {
    if (not visited[next]) {
      dfs(next, visited);
    }
  }
}

void bfs(int start, vector<bool> &visited) {
  queue<int> q;

  q.push(start);
  visited[start] = true;

  while(not q.empty()) {
    int cur = q.front();
    q.pop();

    cout << cur << " ";

    for(int next : graph[cur]) {
      if (not visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }

  cout << endl;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, m, start;
  cin >> n >> m >> start;

  graph = vector<vector<int>>(n + 1);

  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  for(int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  vector<bool> visited(n + 1, false);
  dfs(start, visited);
  cout << endl;

  visited = vector<bool>(n + 1, false);
  bfs(start, visited);

  return 0;
}

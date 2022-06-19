#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

int n, m;
bool graph[101][101];
bool visited[101];

int dfs(int cur) {
  int count = 1;
  visited[cur] = true;

  for(int i = 1; i <= n; i++) {
    if (graph[cur][i] && !visited[i]) {
      count += dfs(i);
    }
  }

  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    graph[from][to] = true;
    graph[to][from] = true;
  }

  cout << dfs(1) - 1 << endl;

  return 0;
}

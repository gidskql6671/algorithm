#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n, m, r, cnt = 1;
int visited[100001];
vector<vector<int>> graph(100001);

void dfs(int cur) {
  visited[cur] = cnt++;

  for(int i = 0; i < graph[cur].size(); i++) {
    int next = graph[cur][i];

    if (!visited[next]) {
       dfs(next);
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

  dfs(r);

  for(int i = 1; i <= n; i++) {
    cout << visited[i] << "\n";
  }

  return 0;
}

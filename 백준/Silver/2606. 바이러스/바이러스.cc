#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int n;
vector<int> graph[101];

int bfs(int start) {
  bool visited[101] = { false };
  queue<int> q;

  q.push(start);
  visited[start] = true;

  int count = 0;
  while(not q.empty()) {
    int cur = q.front();
    q.pop();
    count++;

    for(int next : graph[cur]) {
      if (not visited[next]) {
        q.push(next);
        visited[next] = true;
      }
    }
  }

  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  cout << bfs(1) - 1 << endl;

  return 0;
}

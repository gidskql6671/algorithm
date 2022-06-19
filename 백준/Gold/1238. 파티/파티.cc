#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n, m, x;
vector<pair<int, int>> graph[1001];

int dijkstra(int start, int end) {
  int dist[1001];
  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    int curDist = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    for (int i = 0; i < graph[cur].size(); i++) {
      int next = graph[cur][i].first;
      int nextDist = graph[cur][i].second;

      if (dist[next] > nextDist + curDist) {
        dist[next] = nextDist + curDist;
        pq.push({dist[next], next});
      }
    }
  }

  return dist[end];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> m >> x;
  for (int i = 0; i < m; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    graph[from].push_back({to, weight});
  }

  int maxDist = 0;
  for(int i = 1; i <= n; i++) {
    if (i == x) {
      continue;
    }
    maxDist = max(maxDist, dijkstra(i, x) + dijkstra(x, i));
  }

  cout << maxDist << endl;

  return 0;
}

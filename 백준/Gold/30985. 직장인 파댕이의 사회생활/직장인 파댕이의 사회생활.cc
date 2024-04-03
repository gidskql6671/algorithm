#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int n, m, k;
vector<pair<int, ll>> edges[100001];

vector<ll> dijkstra(int start) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  vector<ll> distance = vector<ll>(n + 1, __LONG_LONG_MAX__);

  pq.push({0, start});
  distance[start] = 0;

  while(not pq.empty()) {
    ll dist = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (distance[cur] < dist) {
      continue;
    }

    for(pair<int, ll> next : edges[cur]) {
      int nNode = next.first;
      ll cost = next.second;

      if (dist + cost < distance[nNode]) {
        pq.push({dist + cost, nNode});
        distance[nNode] = dist + cost;
      }
    }
  }

  return distance;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> m >> k;

  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }

  vector<ll> distFrom1 = dijkstra(1);
  vector<ll> distFromN = dijkstra(n);

  ll result = __LONG_LONG_MAX__;
  for(int i = 1; i <= n; i++) {
    ll elevatorCost;
    cin >> elevatorCost;

    if (elevatorCost == -1) {
      continue;
    }

    ll startToElevator = distFrom1[i];
    if (startToElevator == __LONG_LONG_MAX__) {
      continue;
    }

    ll elevatorToEnd = distFromN[i];
    if (elevatorToEnd == __LONG_LONG_MAX__) {
      continue;
    }

    result = min(result, startToElevator + elevatorToEnd + (elevatorCost * (k - 1)));
  }

  if (result == __LONG_LONG_MAX__) {
    cout << -1 << endl;
  }
  else {
    cout << result << endl;
  }

  return 0;
}

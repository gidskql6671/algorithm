#include <bits/stdc++.h>
#define INF 987654321012L
typedef long long ll;
using namespace std;


struct Comp {
  bool operator()(pair<ll, int> a, pair<ll, int> b) {
    if (a.first == b.first) {
      return a.second < b.second;
    }
    return a.first > b.first;
  }
};

int n, m, k;
vector<pair<ll, int>> edges[100001];
ll totalDist[100001];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, Comp> pq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> m >> k;

  for(int i = 0; i <= n; i++) {
    totalDist[i] = INF;
  }

  for(int i = 0; i < m; i++) {
    int a, b, weight;
    cin >> a >> b >> weight;

    edges[b].push_back({weight, a});
  }

  for(int i = 0; i < k; i++) {
    int num;
    cin >> num;
    totalDist[num] = 0;

    for(pair<int, int> next: edges[num]) {
      pq.push(next);
    }
  }

  while(not pq.empty()) {
    ll dist = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (dist >= totalDist[cur]) {
      continue;
    }

    totalDist[cur] = dist;

    for(pair<ll, int> next : edges[cur]) {
      ll weight = next.first;
      int nextNode = next.second;
      if (dist + weight < totalDist[nextNode]) {
        pq.push({dist + weight, nextNode});
      }
    }
  }

  ll maxDist = 0, maxCity = 0;
  for(int i = 1; i <= n; i++) {
    if (maxDist < totalDist[i]) {
      maxDist = totalDist[i];
      maxCity = i;
    }
  }

  cout << maxCity << "\n" << maxDist << endl;

  return 0;
}

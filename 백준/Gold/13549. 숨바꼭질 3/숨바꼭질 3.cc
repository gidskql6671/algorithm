#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


bool visited[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, k;
  cin >> n >> k;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, n});
  while(not pq.empty()) {
    int distance = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (visited[cur]) {
      continue;
    }
    else {
      visited[cur] = true;
    }

    if (cur == k) {
      cout << distance << endl;
      break;
    }

    if (cur < 100000) {
      pq.push({distance, cur * 2});
    }

    pq.push({distance + 1, cur - 1});
    pq.push({distance + 1, cur + 1});
  }

  return 0;
}

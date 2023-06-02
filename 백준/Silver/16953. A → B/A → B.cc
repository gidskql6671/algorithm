#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  ll a, b;
  cin >> a >> b;

  queue<pair<ll, int>> q;
  q.push({a, 1});
  while(not q.empty()) {
    ll cur = q.front().first;
    int count = q.front().second;
    q.pop();

    if (cur == b) {
      cout << count << endl;

      return 0;
    }

    if (cur * 2 <= b) {
      q.push({cur * 2, count + 1});
    }
    if (cur * 10 + 1 <= b) {
      q.push({cur * 10 + 1, count + 1});
    }
  }

  cout << -1 << endl;

  return 0;
}

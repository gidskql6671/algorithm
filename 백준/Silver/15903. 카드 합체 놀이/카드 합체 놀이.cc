#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, m;
  cin >> n >> m;

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    pq.push(num);
  }

  for (int i = 0; i < m; i++) {
    ll num1 = pq.top(); pq.pop();
    ll num2 = pq.top(); pq.pop();
    ll sum = num1 + num2;

    pq.push(sum);
    pq.push(sum);
  }

  ll result = 0;
  while(!pq.empty()) {
    result += pq.top();
    pq.pop();
  }

  cout << result << endl;

  return 0;
}

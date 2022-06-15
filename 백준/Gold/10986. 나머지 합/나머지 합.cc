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

  vector<ll> counts(m, 0);
  ll sum = 0;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;

    sum += tmp;

    counts[sum % m]++;
  }

  ll result = 0;
  for(int i = 0; i < m; i++) {
    result += counts[i] * (counts[i] - 1) / 2; // 1 + 2 + ... + counts[i]
  }
  result += counts[0];

  cout << result << endl;

  return 0;
}

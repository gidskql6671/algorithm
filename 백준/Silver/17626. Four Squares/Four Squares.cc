#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> dp(n + 1, 0);
  dp[1] = 1;

  for(int i = 2; i <= n; i++) {
    int minVal = INF;
    for(int j = 1; j * j <= i; j++) {
      minVal = min(minVal, dp[i - j * j]);
    }

    dp[i] = minVal + 1;
  }

  cout << dp[n] << endl;

  return 0;
}

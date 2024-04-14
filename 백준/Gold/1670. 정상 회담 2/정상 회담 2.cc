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

  ll div = 987654321;
  ll dp[10001] = {0};
  dp[0] = 1;
  dp[2] = 1;
  for(int i = 4; i <= n; i+= 2) {
    for(int j = 0; j <= i - 2; j+= 2) {
      dp[i] = (dp[i] + (dp[j] * dp[i - 2 - j]) % div) % div;
    }
  }

  cout << dp[n] << endl;

  return 0;
}

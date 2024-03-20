#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int dp[10001][4] = {0};
  for(int i = 1; i <= 3; i++) {
    for(int j = 1; j <= i; j++) {
      dp[i][j] = 1;
    }
  }

  for(int i = 4; i <= 10000; i++) {
    dp[i][1] = dp[i - 1][1];
    dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
  }

  int T, n;
  cin >> T;
  while(T--) {
    cin >> n;

    cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
  }


  return 0;
}

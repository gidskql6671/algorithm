#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int smallJump[21], middleJump[21], largeJump;
int dp[24][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  for(int i = 1; i < n; i++) {
    cin >> smallJump[i] >> middleJump[i];
  }

  cin >> largeJump;

  for(int i = 1; i <= n; i++) {
    dp[i][0] = dp[i][1] = INF;
  }
  dp[1][0] = 0;

  for(int i = 1; i < n; i++) {
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + smallJump[i]);
    dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + smallJump[i]);
    dp[i + 2][0] = min(dp[i + 2][0], dp[i][0] + middleJump[i]);
    dp[i + 2][1] = min(dp[i + 2][1], dp[i][1] + middleJump[i]);
    dp[i + 3][1] = min(dp[i + 3][1], dp[i][0] + largeJump);
  }

  cout << min(dp[n][0], dp[n][1]) << endl;

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n;
int dp[1001][3];
int cost[1001][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> cost[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    dp[0][i] = cost[0][i];
  }
  for (int i = 1; i < n; i++) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
  }

  int result = INF;
  for(int i = 0; i < 3; i++) {
    result = min(result, dp[n - 1][i]);
  }
  cout << result << endl;

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


char board[2001][2001];
int dp[2001][2001][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, m, partN;
  cin >> n >> m >> partN;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> board[i][j];
    }
  }

  for(int k = 0; k <= 1; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];

        char expectedColor = (i + j + k) % 2 == 0 ? 'B' : 'W';
        if (board[i][j] != expectedColor) {
          dp[i][j][k]++;
        }
      }
    }
  }

  int result = INF;
  for(int k = 0; k <= 1; k++) {
    for(int i = partN; i <= n; i++) {
      for(int j = partN; j <= m; j++) {
        int changedVal = dp[i][j][k] - dp[i - partN][j][k] - dp[i][j - partN][k] + dp[i - partN][j - partN][k];
        result = min(result, changedVal);
      }
    }
  }

  cout << result << endl;

  return 0;
}

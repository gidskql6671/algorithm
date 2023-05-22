#include <bits/stdc++.h>
#define INF INT_MAX
typedef long long ll;

using namespace std;

int matrix[501][2], dp[501][501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;

  cin >> n;

	for (int i = 1; i <= n; i++) {
    int a, b;
		cin >> a >> b;
		matrix[i][0] = a;
		matrix[i][1] = b;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; i + j <= n; j++) {
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++) {
				dp[j][i + j] = min(
          dp[j][i + j],
          dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]
          );
			}
		}

	}

	cout << dp[1][n] << endl;

  return 0;
}
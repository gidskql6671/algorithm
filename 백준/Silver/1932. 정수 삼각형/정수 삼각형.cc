#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[501][501];
int dp[501][501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
      cin >> arr[i][j];
    }
  }

  dp[0][0] = arr[0][0];
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j <= i; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + arr[i + 1][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
    }
  }

  int maxSum = 0;
  for(int i = 0; i < n; i++) {
    maxSum = max(maxSum, dp[n - 1][i]);
  }

  cout << maxSum << endl;

  return 0;
}
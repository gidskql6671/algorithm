#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n;
int weights[31];
bool dp[31][55001]; // -15000 ~ 40000

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> weights[i];
  }

  dp[0][15000] = true;
  for(int i = 1; i <= n; i++) {
    int weight = weights[i];

    for(int j = 0; j <= 55000; j++) {
      dp[i][j] = dp[i - 1][j];

      if (j - weight >= 0 and dp[i - 1][j - weight]) {
        dp[i][j] = true;
      }
      else if (j + weight <= 50000 and dp[i - 1][j + weight]) {
        dp[i][j] = true;
      }
    }
  }

  int k;
  cin >> k;
  for(int i = 0; i < k; i++) {
    int num;
    cin >> num;

    cout << (dp[n][num + 15000] ? "Y" : "N") << endl;
  }

  return 0;
}

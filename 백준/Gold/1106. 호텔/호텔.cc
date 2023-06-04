#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


pair<int, int> arr[21];
int dp[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int c, n;
  cin >> c >> n;

  for(int i = 1; i <= n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  for(int i = 1; i <= n; i++) {
    int cost = arr[i].first;
    int customer = arr[i].second;

    for(int j = 1; j <= 100000; j++) {
      if (cost <= j) {
        dp[j] = max(dp[j], dp[j - cost] + customer);
      }
    }
  }

  for(int i = 1; i <= 100000; i++) {
    if (dp[i] >= c) {
      cout << i << endl;

      break;
    }
  }

  return 0;
}

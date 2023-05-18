#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n, k;

int solve(int left, int right, int result) {
  if (left > right) {
    return result;
  }

  int mid = (left + right) / 2;

  int lessOrEqualsCount = 0;
  for(int i = 1; i <= n; i++) {
    lessOrEqualsCount += min(mid / i, n);
  }

  if (lessOrEqualsCount >= k) {
    return solve(left, mid - 1, mid);
  }
  else {
    return solve(mid + 1, right, result);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> k;

  cout << solve(1, k, -1) << endl;

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, k;
  cin >> n >> k;

  int counts[10001] = {0};
  for(int i = 1; i <= n; i++) {
    if (n % i == 0) {
      counts[i]++;
    }
  }

  int count = 0;
  for(int i = 1; i <= n; i++) {
    if (counts[i] > 0) {
      count++;
    }

    if (count == k) {
      cout << i << endl;

      return 0;
    }
  }

  cout << 0 << endl;

  return 0;
}
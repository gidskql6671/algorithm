#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;

  while(T--) {
    ll n;
    cin >> n;

    if (0 <= n && n <= 2) {
      cout << 2 << endl;
      continue;
    }

    for (ll i = n;; i++) {
      ll sqrtVal = sqrt(i);
      bool isPrime = true;
      for(ll j = 2; j <= sqrtVal + 1; j++) {
        if (i % j == 0) {
          isPrime = false;
          break;
        }
      }

      if (isPrime) {
        cout << i << endl;
        break;
      }
    }
  }

  return 0;
}
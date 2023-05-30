#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  ll n;
  cin >> n;

  // (n - 2) + (n - 3) + ... + 2 + 1 == (n - 2)(n - 1) / 2
  // (n - 3) + (n - 2) + ... + 2 + 1 == (n - 3)(n - 2) / 2
  ll result = 0;
  for(int i = 1; i <= n - 2; i++) {
    result += (n - 1 - i) * (n - i) / 2;
  }
  cout << result << "\n3\n";

  return 0;
}

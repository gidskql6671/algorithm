#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  ll result = 1;
  for(int i = 1; i <= n; i++) {
    result *= i;

    while(result % 10 == 0) {
      result /= 10;
    }

    result %= 10000000;
  }

  cout << result % 10 << endl;

  return 0;
}

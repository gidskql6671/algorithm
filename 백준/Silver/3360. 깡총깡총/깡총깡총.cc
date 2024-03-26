#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int n, divider = 1000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;
  ll result = 0;

  while(n >= 0) {
    result += 1 + n / 2;
    n -= 3;
  }

  cout << result % divider << endl;

  return 0;
}

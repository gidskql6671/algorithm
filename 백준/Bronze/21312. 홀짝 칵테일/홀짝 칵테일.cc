#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int a, b, c;
  cin >> a >> b >> c;

  int result = 1;
  if (a % 2 == 0 and b % 2 == 0 and c % 2 == 0) {
    result = a * b * c;
  }
  else {
    if (a % 2) {
      result *= a;
    }
    if (b % 2) {
      result *= b;
    }
    if (c % 2) {
      result *= c;
    }
  }

  cout << result << endl;

  return 0;
}

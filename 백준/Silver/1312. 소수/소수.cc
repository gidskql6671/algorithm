#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int a, b, n;
  cin >> a >> b >> n;

  int quotient = a / b;
  a %= b;
  for(int i = 0; i < n; i++) {
    a *= 10;

    quotient = a / b;
    a %= b;
  }

  cout << quotient << endl;

  return 0;
}

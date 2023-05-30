#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int a1, a0, c, n0;
  cin >> a1 >> a0 >> c >> n0;

  int val1 = a1 * n0 - c * n0 + a0;
  int val2 = a1 * 100000 - c * 100000 + a0;

  cout << (val1 <= 0 and val2 <= 0 ? 1 : 0) << endl;

  return 0;
}

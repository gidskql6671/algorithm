#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int x, n, a, b;

  cin >> x >> n;

  for(int i = 0; i < n; i++) {
    cin >> a >> b;

    x -= a * b;
  }

  cout << (x == 0 ? "Yes" : "No") << endl;


  return 0;
}
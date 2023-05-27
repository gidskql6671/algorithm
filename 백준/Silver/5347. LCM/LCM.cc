#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;

    cout << lcm(max(a, b), min(a, b)) << "\n";
  }

  return 0;
}

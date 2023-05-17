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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  ll a, b;
  cin >> a >> b;

  cout << a * b / gcd(a, b) << endl;

  return 0;
}
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


  int frac1, deno1, frac2, deno2;
  cin >> frac1 >> deno1 >> frac2 >> deno2;

  int frac = frac1 * deno2 + frac2 * deno1;
  int deno = deno1 * deno2;

  int gcdVal = gcd(max(frac, deno), min(frac, deno));

  cout << frac / gcdVal << " " << deno / gcdVal << endl;

  return 0;
}
#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int fib(int n) {
  if (n == 1 || n == 2) {
    return 1;
  }

  return fib(n - 1) + fib(n - 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  cout << fib(n) << " " << n - 2 << endl;

  return 0;
}

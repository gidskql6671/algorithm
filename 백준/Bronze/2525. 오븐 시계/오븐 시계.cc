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

  b += c;
  while(b >= 60) {
    a++;
    b -= 60;

    if (a >= 24) {
      a -= 24;
    }
  }

  cout << a << " " << b << endl;

  return 0;
}

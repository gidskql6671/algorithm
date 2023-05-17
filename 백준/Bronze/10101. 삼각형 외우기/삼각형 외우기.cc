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

  if (a + b + c == 180) {
    if (a == b and b == c) {
      cout << "Equilateral\n";
    }
    else if (a == b or b == c or a == c) {
      cout << "Isosceles\n";
    }
    else {
      cout << "Scalene\n";
    }
  }
  else {
    cout << "Error\n";
  }

  return 0;
}
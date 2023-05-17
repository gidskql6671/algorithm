#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);


  int T;
  cin >> T;

  while(T--) {
    int c;
    cin >> c;

    int quarter = 0, dime = 0, nickel = 0, penny = 0;
    while(c >= 25) {
      quarter++;
      c -= 25;
    }
    while(c >= 10) {
      dime++;
      c -= 10;
    }
    while(c >= 5) {
      nickel++;
      c -= 5;
    }
    while(c >= 1) {
      penny++;
      c -= 1;
    }

    printf("%d %d %d %d\n", quarter, dime, nickel, penny);
  }


  return 0;
}
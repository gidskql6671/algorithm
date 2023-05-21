#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;

  while(T--) {
    int a, b;
    cin >> a >> b;

    int result = a % 10;
    for(int i = 1; i < b; i++) {
      result = (result * a) % 10;
    }

    cout << (result > 0 ? result : 10) << endl;
  }

  return 0;
}

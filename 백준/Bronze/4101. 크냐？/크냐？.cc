#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  while(true) {
    int a, b;
    cin >> a >> b;

    if (a == 0 and b == 0) {
      break;
    }

    cout << (a > b ? "Yes" : "No") << endl;
  }

  return 0;
}

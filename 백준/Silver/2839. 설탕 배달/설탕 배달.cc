#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  int count5 = n / 5;
  int count3 = 0;

  int result = -1;
  while(count5 >= 0) {
    int kilo = count5 * 5 + count3 * 3;

    if (kilo == n) {
      result = count5 + count3;
      break;
    }
    else if (kilo < n) {
      count3++;
    }
    else {
      count5--;
    }
  }

  cout << result << endl;

  return 0;
}

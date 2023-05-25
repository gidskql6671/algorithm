#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, count = 0;
  cin >> n;

  while(true) {
    if (n < 0) {
      count = -1;
      break;
    }

    if (n % 5 == 0) {
      count += n / 5;
      break;
    }

    count++;
    n -= 2;
  }

  cout << count << endl;

  return 0;
}

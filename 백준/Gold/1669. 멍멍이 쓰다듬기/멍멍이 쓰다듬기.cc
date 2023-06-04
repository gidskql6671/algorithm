#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int a, b;
  cin >> a >> b;

  int diff = b - a;
  int day = 0;
  int stand = 1;
  while(diff > 0) {
    if (diff <= stand) {
      day++;
      break;
    }

    diff -= stand * 2;

    stand += 1;
    day += 2;
  }

  cout << day << endl;

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, k;
  cin >> n >> k;

  int hour = 0, minute = 0, second = 0;
  n = (60 * 60) * (n + 1);
  char time[10];
  int count = 0;
  for(int i = 0; i < n; i++) {
    sprintf(time, "%02d%02d%02d", hour, minute, second);

    bool isContainsK = false;
    for(int j = 0; j < 6; j++) {
      if (time[j] == '0' + k) {
        isContainsK = true;
        break;
      }
    }

    if (isContainsK) {
      count++;
    }

    second++;
    if (second >= 60) {
      minute++;
      second = 0;
    }
    if (minute >= 60) {
      hour++;
      minute = 0;
    }
  }

  cout << count << endl;

  return 0;
}

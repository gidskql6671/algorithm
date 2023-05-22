#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int cy, cm, cd, dy, dm, dd;
  cin >> cy >> cm >> cd >> dy >> dm >> dd;

  if (cy + 1000 < dy) {
    cout << "gg\n";
    return 0;
  }
  else if (cy + 1000 == dy) {
    if (cm < dm) {
      cout << "gg\n";
      return 0;
    }
    else if (cm == dm) {
      if (cd <= dd) {
        cout << "gg\n";
        return 0;
      }
    }
  }

  int dDay = 0;
  while(not (cy == dy and cm == dm and cd == dd)) {
    dDay++;

    cd++;
    if (cm == 1 or cm == 3 or cm == 5 or cm == 7 or cm == 8 or cm == 10 or cm == 12) {
      if (cd > 31) {
        cd = 1;
        cm++;
      }
    }
    else if (cm == 4 or cm == 6 or cm == 9 or cm == 11) {
      if (cd > 30) {
        cd = 1;
        cm++;
      }
    }
    else {
      bool isLeapYear = false;
      if (cy % 400 == 0) {
        isLeapYear = true;
      }
      else if (cy % 100 != 0 and cy % 4 == 0) {
        isLeapYear = true;
      }

      if (isLeapYear) {
        if (cd > 29) {
          cd = 1;
          cm++;
        }
      }
      else if (cd > 28) {
        cd = 1;
        cm++;
      }
    }

    if (cm > 12) {
      cm = 1;
      cy++;
    }
  }

  cout << "D-" << dDay << endl;

  return 0;
}

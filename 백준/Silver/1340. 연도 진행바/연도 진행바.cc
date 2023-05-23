#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


string months[] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cout << fixed;
  cout.precision(9);

  string month;
  int day, year, hour, minute, monthInt;
  char tmp;

  cin >> month >> day >> tmp >> year >> hour >> tmp >> minute;

  for(int i = 0; i < 12; i++) {
    if (months[i] == month) {
      monthInt = i + 1;
      break;
    }
  }

  int elapsedDays = 0;
  for(int i = 1; i < monthInt; i++) {
    if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12) {
      elapsedDays += 31;
    }
    else if (i == 2) {
      if (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)) {
        elapsedDays += 29;
      }
      else {
        elapsedDays += 28;
      }
    }
    else {
      elapsedDays += 30;
    }
  }

  elapsedDays += day - 1;

  int elapsedMinutes = elapsedDays * 24 * 60;
  elapsedMinutes += hour * 60;
  elapsedMinutes += minute;

  double totalMinutes;
  if (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)) {
    totalMinutes = (366 * 24 * 60.0);
  }
  else {
    totalMinutes = (365 * 24 * 60.0);
  }
  double percent = elapsedMinutes / totalMinutes * 100;

  cout << percent << endl;

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  double totalCredit = 0;
  double totalScore = 0;
  for(int i = 0; i < 20; i++) {
    string name, grade;
    double credit;

    cin >> name >> credit >> grade;
    totalCredit += credit;

    if (grade == "A+") {
      totalScore += 4.5 * credit;
    }
    else if (grade == "A0") {
      totalScore += 4.0 * credit;
    }
    else if (grade == "B+") {
      totalScore += 3.5 * credit;
    }
    else if (grade == "B0") {
      totalScore += 3.0 * credit;
    }
    else if (grade == "C+") {
      totalScore += 2.5 * credit;
    }
    else if (grade == "C0") {
      totalScore += 2.0 * credit;
    }
    else if (grade == "D+") {
      totalScore += 1.5 * credit;
    }
    else if (grade == "D0") {
      totalScore += 1.0 * credit;
    }
    else if (grade == "P") {
      totalCredit -= credit;
    }
  }

  cout << totalScore / totalCredit << endl;

  return 0;
}
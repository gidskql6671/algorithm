#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int userRank = 25, star = 0, consecutiveWin = 0;
int needStar[26];

void processWin() {
  star++;
  consecutiveWin++;

  if (userRank >= 6 && consecutiveWin >= 3) {
    if (star > needStar[userRank]) {
      star = 1;
      userRank--;
    }

    star++;
  }

  if (star > needStar[userRank]) {
    star = 1;
    userRank--;
  }
}

void processLoss() {
  consecutiveWin = 0;

  if (userRank < 1 or 20 < userRank) {
    return;
  }

  star--;
  if (star >= 0) {
    return;
  }

  if (userRank == 20) {
    star = 0;
    return;
  }

  userRank++;
  star = needStar[userRank] - 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  needStar[0] = INF;
  for(int i = 1; i <= 25; i++) {
    if (i <= 10) {
      needStar[i] = 5;
    }
    else if (i <= 15) {
      needStar[i] = 4;
    }
    else if (i <= 20) {
      needStar[i] = 3;
    }
    else {
      needStar[i] = 2;
    }
  }

  string rounds;
  cin >> rounds;

  for(char round : rounds) {
    round == 'W' ? processWin() : processLoss();
  }

  if (userRank == 0) {
    cout << "Legend\n";
  }
  else {
    cout << userRank << endl;
  }

  return 0;
}

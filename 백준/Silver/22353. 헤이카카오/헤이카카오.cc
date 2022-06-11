#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

double solve(int timePerGame, int initWinPercent, double increaseWinPercent) {
  double result = 0;
  double winPercent = (double) initWinPercent / 100;
  double reachCurGamePercent = 1;
  int elapsedTime = timePerGame;
  increaseWinPercent /= 100;

  while(winPercent < 1) {
    result += elapsedTime * reachCurGamePercent * winPercent;

    reachCurGamePercent *= (1 - winPercent);
    winPercent += winPercent * increaseWinPercent;
    elapsedTime += timePerGame;
  }

  result += elapsedTime * reachCurGamePercent;

  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(7);

  int a, d, k;
  cin >> a >> d >> k;

  cout << solve(a, d, k) << endl;

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  string board;
  cin >> board;

  for(int i = 0; i < board.size() - 1; i++) {
    if (board[i] == 'X') {
      bool isAllX = true;
      for(int j = i; j < i + 4; j++) {
        if (j >= board.size() or board[j] == '.') {
          isAllX = false;
          break;
        }
      }

      if (isAllX) {
        for(int j = i; j < i + 4; j++) {
          board[j] = 'A';
        }
      }
      else {
        if (board[i] == 'X' and board[i + 1] == 'X') {
          board[i] = 'B';
          board[i + 1] = 'B';
        }
      }
    }
  }

  bool isCovered = true;
  for(int i = 0; i < board.size(); i++) {
    if (board[i] == 'X') {
      isCovered = false;
      break;
    }
  }

  if (isCovered) {
    cout << board << endl;
  }
  else {
    cout << -1 << endl;
  }

  return 0;
}

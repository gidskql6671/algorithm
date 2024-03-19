#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int board[9][9];
vector<pair<int, int>> blanks;
vector<set<int>> remainRows(9), remainCols(9);
vector<vector<set<int>>> remainArea(3, vector<set<int>>(3));

vector<int> getPossibleNums(int y, int x) {
  vector<int> result;

  for(int n1 : remainRows[y]) {
    for(int n2 : remainCols[x]) {
      if (n1 < n2) {
        break;
      }

      for(int n3 : remainArea[y / 3][x / 3]) {
        if (n2 < n3) {
          break;
        }

        if (n1 == n2 and n2 == n3) {
          result.push_back(n1);
        }
      }
    }
  }

  return result;
}

bool recur(int cur) {
  if (cur == blanks.size()) {
    return true;
  }

  int y = blanks[cur].first;
  int x = blanks[cur].second;
  vector<int> possibleNums = getPossibleNums(y, x);

  for(int num : possibleNums) {
    board[y][x] = num;
    remainRows[y].erase(num);
    remainCols[x].erase(num);
    remainArea[y / 3][x / 3].erase(num);

    int result = recur(cur + 1);
    if (result) {
      return true;
    }

    remainArea[y / 3][x / 3].insert(num);
    remainCols[x].insert(num);
    remainRows[y].insert(num);
    board[y][x] = 0;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  for(int i = 0; i < 9; i++) {
    for(int j = 1; j <= 9; j++) {
      remainRows[i].insert(j);
      remainCols[i].insert(j);
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      for(int k = 1; k <= 9; k++) {
        remainArea[i][j].insert(k);
      }
    }
  }

  for(int i = 0; i < 9; i++) {
    string line;
    cin >> line;

    for(int j = 0; j < 9; j++) {
      board[i][j] = line[j] - '0';

      if (board[i][j] == 0) {
        blanks.push_back({i, j});
      }
      else {
        remainRows[i].erase(board[i][j]);
        remainCols[j].erase(board[i][j]);
        remainArea[i / 3][j / 3].erase(board[i][j]);
      }
    }
  }

  recur(0);

  for(int y = 0; y < 9; y++) {
    for(int x = 0; x < 9; x++) {
      cout << board[y][x];
    }
    cout << "\n";
  }


  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


bool visited[6][6];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  string str;
  cin >> str;

  int firstRow = str[0] - 'A';
  int firstCol = str[1] - '1';
  visited[firstRow][firstCol] = true;

  int prevRow = firstRow, prevCol = firstCol;
  int row, col;
  for(int i = 1; i < 36; i++) {
    string str;
    cin >> str;

    row = str[0] - 'A';
    col = str[1] - '1';

    if (visited[row][col]) {
      cout << "Invalid\n";

      return 0;
    }

    visited[row][col] = true;

    if (abs(row - prevRow) == 2 and abs(col - prevCol) == 1) {
    }
    else if (abs(row - prevRow) == 1 and abs(col - prevCol) == 2) {
    }
    else {
      cout << "Invalid\n";

      return 0;
    }

    prevRow = row;
    prevCol = col;
  }

  if (
    (abs(row - firstRow) == 2 and abs(col - firstCol) == 1) or
    (abs(row - firstRow) == 1 and abs(col - firstCol) == 2)
  ) {
    cout << "Valid\n";
  }
  else {
    cout << "Invalid\n";
  }

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, m, bridgeY;
  cin >> n >> m >> bridgeY;

  vector<vector<char>> arr(n + 1, vector<char>(m + 1));
  for(int i = 1; i <= m; i++) {
    int tmp;
    cin >> tmp;

    for(int j = 1; j <= tmp; j++) {
      arr[j][i] = '#';
    }
    for(int j = tmp + 1; j <= n; j++) {
      arr[j][i] = '.';
    }
  }

  for(int x = 1; x <= m; x++) {
    if (arr[bridgeY][x] == '#') {
      arr[bridgeY][x] = '*';
      continue;
    }

    arr[bridgeY][x] = '-';
    if (x % 3 == 0) {
      int y = bridgeY - 1;
      while(arr[y][x] == '.') {
        arr[y][x] = '|';
        y--;
      }
    }
  }

  for(int i = n; i >= 1; i--) {
    for(int j = 1; j <= m; j++) {
      cout << arr[i][j];
    }
    cout << "\n";
  }

  return 0;
}

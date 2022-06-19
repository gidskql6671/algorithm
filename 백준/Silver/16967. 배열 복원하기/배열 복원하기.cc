#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, m, y, x;
  cin >> n >> m >> y >> x;

  vector<vector<int>> arr(n + y, vector<int>(m + x, 0));
  for(int i = 0; i < n + y; i++) {
    for(int j = 0; j < m + x; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> result(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (i < y || j < x) {
        result[i][j] = arr[i][j];
      } else {
        result[i][j] = arr[i][j] - result[i - y][j - x];
      }
      cout << result[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}

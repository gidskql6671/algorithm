#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> arr(n, vector<int>(m));
  vector<int> mapper(n);
  for(int i = 0; i < n; i++) {
    mapper[i] = i;
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  while(q--) {
    int oper, i, j;
    cin >> oper >> i >> j;

    if (oper == 0) {
      int k;
      cin >> k;

      int row = mapper[i];
      arr[row][j] = k;
    }
    else {
      int tmp = mapper[i];
      mapper[i] = mapper[j];
      mapper[j] = tmp;
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << arr[mapper[i]][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}

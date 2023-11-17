#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int n, m;
int arr[1025][1025], cumSum[1025][1025];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> arr[i][j];

      cumSum[i][j] = cumSum[i - 1][j] + cumSum[i][j - 1] - cumSum[i - 1][j - 1] + arr[i][j];
    }
  }

  for(int i = 0; i < m; i++) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;

    cout << cumSum[y2][x2] - cumSum[y2][x1 - 1] - cumSum[y1 - 1][x2] + cumSum[y1 - 1][x1 - 1] << "\n";
  }


  return 0;
}

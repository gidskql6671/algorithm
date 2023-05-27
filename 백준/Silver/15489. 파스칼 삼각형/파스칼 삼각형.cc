#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


ll pascal[31][31];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  for(int i = 0; i <= 30; i++) {
    for(int j = 0; j <= 30; j++) {
      pascal[i][j] = 1;
    }
  }

  for(int i = 3; i <= 30; i++) {
    for(int j = 2; j < i; j++) {
      pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }
  }

  int r, c, w;
  cin >> r >> c >> w;

  ll result = 0;
  for(int i = r; i < r + w; i++) {
    for(int j = c; j < c + i - r + 1; j++) {
      result += pascal[i][j];
    }
  }

  cout << result << endl;

  return 0;
}

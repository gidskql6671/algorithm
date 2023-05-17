#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  int minY = INF, minX = INF, maxY = -INF, maxX = -INF;
  for(int i = 0; i < n; i++) {
    int y, x;
    cin >> y >> x;

    minY = min(minY, y);
    minX = min(minX, x);
    maxY = max(maxY, y);
    maxX = max(maxX, x);
  }

  cout << (maxY - minY) * (maxX - minX) << endl;

  return 0;
}
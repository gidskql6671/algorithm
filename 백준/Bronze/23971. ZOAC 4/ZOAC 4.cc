#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int h, w, n, m;
  cin >> h >> w >> n >> m;

  int rowCount = h / (n + 1);
  if (h % (n + 1)) {
    rowCount++;
  }

  int colCount = w / (m + 1);
  if (w % (m + 1)) {
    colCount++;
  }

  cout << rowCount * colCount << endl;

  return 0;
}

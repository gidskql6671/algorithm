#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;

  while(T--) {
    int n;
    cin >> n;

    int minVal = INF, maxVal = -INF;
    for(int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;

      minVal = min(minVal, tmp);
      maxVal = max(maxVal, tmp);
    }

    cout << minVal << " " << maxVal << "\n";
  }

  return 0;
}

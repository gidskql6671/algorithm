#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, m;

  cin >> n >> m;

  int basket[101] = {0};
  for(int i = 0; i < m; i++) {
    int l, r, num;
    cin >> l >> r >> num;

    for(int j = l; j <= r; j++) {
      basket[j] = num;
    }
  }

  for(int i = 1; i <= n; i++) {
    cout << basket[i] << " ";
  }

  cout << "\n";

  return 0;
}
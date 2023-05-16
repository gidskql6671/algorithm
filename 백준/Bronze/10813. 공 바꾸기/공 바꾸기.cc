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

  int basket[101];
  for(int i = 1; i <= n; i++) {
    basket[i] = i;
  }

  for(int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;

    int tmp = basket[l];
    basket[l] = basket[r];
    basket[r] = tmp;
  }

  for(int i = 1; i <= n; i++) {
    cout << basket[i] << " ";
  }
  cout << "\n";

  return 0;
}
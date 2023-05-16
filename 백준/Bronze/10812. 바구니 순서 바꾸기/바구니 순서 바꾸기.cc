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

  // O(mn^2) == 대략 10^6
  for(int i = 0; i < m; i++) {
    int left, right, mid;
    cin >> left >> right >> mid;

    for(int j = 0; j < mid - left; j++) {
      int tmp = basket[left];
      for(int k = left; k < right; k++) {
        basket[k] = basket[k + 1];
      }
      basket[right] = tmp;
    }
  }

  for(int i = 1; i <= n; i++) {
    cout << basket[i] << " ";
  }
  cout << "\n";

  return 0;
}
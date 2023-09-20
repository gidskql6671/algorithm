#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int arr[10000];

void solve() {
  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (next_permutation(arr, arr + n) == false) {
    cout << -1 << endl;
    return;
  }

  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  solve();
  // cout << solve() << endl;

  return 0;
}

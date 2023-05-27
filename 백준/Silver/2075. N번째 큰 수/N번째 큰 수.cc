#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[1501 * 1501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  for(int i = 0; i < n * n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n * n, greater<>());

  cout << arr[n - 1] << endl;

  return 0;
}

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

  vector<double> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  for(int i = 0; i < n - 1; i++) {
    arr[n - 1] += arr[i] / 2;
  }

  cout << arr[n - 1] << endl;

  return 0;
}

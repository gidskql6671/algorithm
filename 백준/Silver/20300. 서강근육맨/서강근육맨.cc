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

  vector<ll> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  ll result = -1;
  if (n % 2 == 0) {
    for(int i = 0; i < n / 2; i++) {
      result = max(result, arr[i] + arr[n - i - 1]);
    }
  }
  else {
    result = arr[n - 1];
    for (int i = 0; i < n / 2; i++) {
      result = max(result, arr[i] + arr[n - i - 2]);
    }
  }

  cout << result << endl;

  return 0;
}

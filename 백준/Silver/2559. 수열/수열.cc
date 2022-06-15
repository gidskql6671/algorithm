#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for(int i = 0 ; i < n; i++) {
    cin >> arr[i];
  }

  int sum = 0;
  for(int i = 0; i < k; i++) {
    sum += arr[i];
  }

  int result = sum;
  for(int i = k; i < n; i++) {
    sum = sum + arr[i] - arr[i - k];

    result = max(result, sum);
  }

  cout << result << endl;

  return 0;
}

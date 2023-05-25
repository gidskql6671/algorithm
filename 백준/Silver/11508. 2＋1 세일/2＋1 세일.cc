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

  sort(arr.begin(), arr.end(), greater<>());

  int cost = 0;
  for(int i = 0; i < n / 3 * 3; i += 3) {
    cost += arr[i] + arr[i + 1];
  }

  for(int i = n / 3 * 3; i < n; i++) {
    cost += arr[i];
  }

  cout << cost << endl;

  return 0;
}

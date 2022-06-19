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

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  int possibleMax = 0;
  for(int i = 0; i < n; i++) {
    if (arr[i] <= possibleMax + 1) {
      possibleMax += arr[i];
    }
    else {
      break;
    }
  }

  cout << possibleMax + 1 << endl;

  return 0;
}

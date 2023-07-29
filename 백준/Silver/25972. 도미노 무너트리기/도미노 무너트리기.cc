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

  vector<pair<int, int>> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr.begin(), arr.end());

  int result = 0, prevX = -1;
  for(int i = 0; i < n; i++) {
    if (arr[i].first > prevX) {
      result++;
    }

    prevX = arr[i].first + arr[i].second;
  }

  cout << result << endl;

  return 0;
}

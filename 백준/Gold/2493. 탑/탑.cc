#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n;
vector<int> arr, result;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;
  arr.assign(n, 0);
  result.assign(n, 0);

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  stack<pair<int, int>> s;
  for(int i = n - 1; i >= 0; i--) {
    int curHeight = arr[i];

    while(not s.empty()) {
      int topHeight = s.top().first;
      int topIndex = s.top().second;

      if (curHeight > topHeight) {
        result[topIndex] = i + 1;
        s.pop();
      }
      else {
        break;
      }
    }

    s.push({curHeight, i});
  }

  for(int i = 0; i < n; i++) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}

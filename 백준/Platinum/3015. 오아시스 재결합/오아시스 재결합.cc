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

  stack<pair<int, int>> s;
  ll count = 0;
  for(int i = 0; i < n; i++) {
    int height;
    cin >> height;

    if (s.empty()) {
      s.push({height, 1});
      continue;
    }

    if (s.top().first > height) {
      count++;
      s.push({height, 1});
    }
    else if (s.top().first == height) {
      int sameCount = s.top().second;
      s.pop();
      count += sameCount;

      if (not s.empty()) {
        count++;
      }

      s.push({height, sameCount + 1});
    }
    else {
      while(not s.empty() and s.top().first < height) {
        count += s.top().second;
        s.pop();
      }

      int sameCount = 1;
      if (not s.empty() and s.top().first == height) {
        sameCount = s.top().second;
        s.pop();
        count += sameCount;

        sameCount++;
      }

      if (not s.empty()) {
        count++;
      }

      s.push({height, sameCount});
    }
  }

  cout << count << endl;

  return 0;
}

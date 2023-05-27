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

  int maxCount = 0;
  map<string, int> m;
  for(int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;

    m[tmp] += 1;
    maxCount = max(maxCount, m[tmp]);
  }

  vector<string> result;
  for(auto ele : m) {
    if (ele.second == maxCount) {
      result.push_back(ele.first);
    }
  }

  sort(result.begin(), result.end());

  cout << result[0] << endl;

  return 0;
}

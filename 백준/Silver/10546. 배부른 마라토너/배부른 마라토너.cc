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

  map<string, int> m;
  for(int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;

    m[tmp] += 1;
  }

  for(int i = 0; i < n - 1; i++) {
    string tmp;
    cin >> tmp;

    m[tmp] -= 1;
  }

  for(auto ele : m) {
    if (ele.second > 0) {
      cout << ele.first << endl;
      break;
    }
  }

  return 0;
}

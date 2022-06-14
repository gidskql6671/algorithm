#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  string str;
  cin >> str;

  int n = str.length();
  set<string> result;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= n - i; j++) {
      string subStr = str.substr(j, i);

      result.insert(subStr);
    }
  }

  cout << result.size() << endl;

  return 0;
}

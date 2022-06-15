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

  int n;
  cin >> n;

  vector<vector<int>> chars(str.length() + 1, vector<int>(26, 0));
  for(int i = 1; i <= str.length(); i++) {
    chars[i][str[i - 1] - 'a']++;

    for(int j = 0; j < 26; j++) {
      chars[i][j] += chars[i - 1][j];
    }
  }

  for(int i = 0; i < n; i++) {
    char charater;
    int l, r;
    cin >> charater >> l >> r;

    cout << chars[r + 1][charater - 'a'] - chars[l][charater - 'a'] << "\n";
  }

  return 0;
}

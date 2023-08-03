#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


bool isPossible = false;
ll visited = 0;
string t;

void solve(string s) {
  if (isPossible) {
    return;
  }

  if (s.size() == t.size()) {
    if (s == t) {
      isPossible = true;
    }

    return;
  }

  if (t.find(s) == string::npos) {
    reverse(s.begin(), s.end());
    if (t.find(s) == string::npos) {
      return;
    }
    reverse(s.begin(), s.end());
  }

  solve(s + "A");

  s += "B";
  reverse(s.begin(), s.end());
  solve(s);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  string s;
  cin >> s >> t;

  solve(s);

  cout << (isPossible ? 1 : 0) << endl;

  return 0;
}

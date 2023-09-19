#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int solve() {
  stack<int> s;

  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    int oper;
    cin >> oper;

    if (oper == 1) {
      int x;
      cin >> x;

      s.push(x);
    }
    else if (oper == 2) {
      if (s.empty()) {
        cout << "-1\n";
      }
      else {
        cout << s.top() << "\n";
        s.pop();
      }
    }
    else if (oper == 3) {
      cout << s.size() << "\n";
    }
    else if (oper == 4) {
      if (s.empty()) {
        cout << "1\n";
      }
      else {
        cout << "0\n";
      }
    }
    else {
      if (s.empty()) {
        cout << "-1\n";
      }
      else {
        cout << s.top() << "\n";
      }
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  solve();
  // cout << solve() << endl;

  return 0;
}

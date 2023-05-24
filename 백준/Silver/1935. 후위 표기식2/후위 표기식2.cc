#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cout << fixed;
  cout.precision(2);

  int n;
  cin >> n;

  string expresion;
  cin >> expresion;

  vector<double> values(n);
  for(int i = 0; i < n; i++) {
    cin >> values[i];
  }

  stack<double> s;
  for(char c : expresion) {
    if ('A' <= c and c <= 'Z') {
      s.push(values[c - 'A']);
    }
    else if (c == '+') {
      double b = s.top(); s.pop();
      double a = s.top(); s.pop();
      s.push(a + b);
    }
    else if (c == '-') {
      double b = s.top(); s.pop();
      double a = s.top(); s.pop();
      s.push(a - b);
    }
    else if (c == '*') {
      double b = s.top(); s.pop();
      double a = s.top(); s.pop();
      s.push(a * b);
    }
    else if (c == '/') {
      double b = s.top(); s.pop();
      double a = s.top(); s.pop();
      s.push(a / b);
    }
  }

  cout << s.top() << endl;

  return 0;
}

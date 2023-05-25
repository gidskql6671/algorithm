#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


string str;
vector<pair<int, int>> parenthesis;
vector<bool> removes;
set<string> result;

void solve(int cur) {
  if (cur >= parenthesis.size()) {
    vector<bool> passStr(str.length(), false);
    for(int i = 0; i < parenthesis.size(); i++) {
      if (removes[i]) {
        passStr[parenthesis[i].first] = true;
        passStr[parenthesis[i].second] = true;
      }
    }

    string r = "";
    for(int i = 0; i < str.length(); i++) {
      if (not passStr[i]) {
        r += str[i];
      }
    }
    result.insert(r);

    return;
  }

  solve(cur + 1);
  removes[cur] = true;
  solve(cur + 1);
  removes[cur] = false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> str;

  stack<int> s;
  for(int i = 0; i < str.length(); i++) {
    if (str[i] == '(') {
      s.push(i);
    }
    else if (str[i] == ')') {
      parenthesis.push_back({s.top(), i});
      removes.push_back(false);
      s.pop();
    }
  }

  solve(0);

  // sort(result.begin(), result.end());
  for(string out : result) {
    if (out == str) {
      continue;
    }
    cout << out << "\n";
  }

  return 0;
}

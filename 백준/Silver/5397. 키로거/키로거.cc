#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;

  while(T--) {
    cin >> str;

    stack<char> leftStack, rightStack;
    for(char c : str) {
      if (c == '<') {
        if (not leftStack.empty()) {
          rightStack.push(leftStack.top());
          leftStack.pop();
        }
      }
      else if (c == '>') {
        if (not rightStack.empty()) {
          leftStack.push(rightStack.top());
          rightStack.pop();
        }
      }
      else if (c == '-') {
        if (not leftStack.empty()) {
          leftStack.pop();
        }
      }
      else {
        leftStack.push(c);
      }
    }

    string result = "";
    while(not leftStack.empty()) {
      result += leftStack.top();
      leftStack.pop();
    }
    reverse(result.begin(), result.end());

    while(not rightStack.empty()) {
      result += rightStack.top();
      rightStack.pop();
    }

    cout << result << "\n";
  }


  return 0;
}

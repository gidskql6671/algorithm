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

  queue<int> q;
  for(int i = 0; i < n; i++) {
    string operation;
    cin >> operation;

    if (operation == "push") {
      int operand;
      cin >> operand;
      q.push(operand);
    }
    else if (operation == "pop") {
      if (q.empty()) {
        cout << -1 << "\n";
      }
      else {
        cout << q.front() << "\n";
        q.pop();
      }
    }
    else if (operation == "size") {
      cout << q.size() << "\n";
    }
    else if (operation == "empty") {
      cout << (q.empty() ? 1 : 0) << "\n";
    }
    else if (operation == "front") {
      if (q.empty()) {
        cout << -1 << "\n";
      }
      else {
        cout << q.front() << "\n";
      }
    }
    else {
      if (q.empty()) {
        cout << -1 << "\n";
      }
      else {
        cout << q.back() << "\n";
      }
    }
  }
  return 0;
}

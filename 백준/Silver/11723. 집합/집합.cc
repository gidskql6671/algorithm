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

  set<int> s;
  while(n--) {
    string operation;
    int operand;
    cin >> operation;

    if (operation == "add") {
      cin >> operand;
      s.insert(operand);
    }
    else if (operation == "remove") {
      cin >> operand;
      s.erase(operand);
    }
    else if (operation == "check") {
      cin >> operand;

      if (s.count(operand) == 1) {
        cout << "1\n";
      }
      else {
        cout << "0\n";
      }
    }
    else if (operation == "toggle") {
      cin >> operand;
      if (s.count(operand) == 1) {
        s.erase(operand);
      }
      else {
        s.insert(operand);
      }
    }
    else if (operation == "all") {
      for(int i = 1; i <= 20; i++) {
        s.insert(i);
      }
    }
    else {
      s.clear();
    }
  }

  return 0;
}

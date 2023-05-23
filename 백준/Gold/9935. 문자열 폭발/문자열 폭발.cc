#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  string str, explodeStr;
  cin >> str >> explodeStr;

  deque<char> dq;
  for(char c : str) {
    dq.push_back(c);

    if (explodeStr.size() <= dq.size()) {
      bool isExplodeStr = true;
      int start = dq.size() - explodeStr.size();
      for(int i = start; i < dq.size(); i++) {
        if (dq[i] != explodeStr[i - start]) {
          isExplodeStr = false;
          break;
        }
      }

      if (isExplodeStr) {
        for(int i = 0; i < explodeStr.size(); i++) {
          dq.pop_back();
        }
      }
    }
  }

  if (dq.empty()) {
    cout << "FRULA\n";
  }
  else {
    for(char c : dq) {
      cout << (char)c;
    }
    cout << endl;
  }

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n, t, type;

int solve() {
  int cycle = 1;
  int count = 0;
  int cur = 0;
  while(true) {
    if (type == 0) {
      if (++count == t) {
        return cur;
      }
    }
    cur = (cur + 1) % n;

    if (type == 1) {
      if (++count == t) {
        return cur;
      }
    }
    cur = (cur + 1) % n;

    if (type == 0) {
      if (++count == t) {
        return cur;
      }
    }
    cur = (cur + 1) % n;

    if (type == 1) {
      if (++count == t) {
        return cur;
      }
    }
    cur = (cur + 1) % n;

    for(int i = 0; i <= cycle; i++) {
      if (type == 0) {
        if (++count == t) {
          return cur;
        }
      }
      cur = (cur + 1) % n;
    }

    for(int i = 0; i <= cycle; i++) {
      if (type == 1) {
        if (++count == t) {
          return cur;
        }
      }
      cur = (cur + 1) % n;
    }
    
    cycle++;
  }

  return cur;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> t >> type;

  cout << solve() << endl;

  return 0;
}

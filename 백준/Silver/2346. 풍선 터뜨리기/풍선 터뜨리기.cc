#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  deque<pair<int, int>> dq;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;

    dq.push_back({a, i + 1});
  }

  while(not dq.empty()) {
    pair<int, int> cur = dq.front();
    dq.pop_front();

    int moveCount = cur.first;
    int index = cur.second;

    cout << index << " ";

    if (dq.empty()) {
      break;
    }

    if (moveCount > 0) {
      for(int i = 1; i < moveCount; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    }
    else {
      for(int i = 0; i > moveCount; i--) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }

  cout << "\n";

  return 0;
}

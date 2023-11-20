#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


struct compare {
  bool operator()(int a, int b) {
    if (abs(a) == abs(b)) {
      return a > b;
    }

    return abs(a) > abs(b);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  priority_queue<int, vector<int>, compare> pq;
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;

    if (num == 0) {
      if (pq.empty()) {
        cout << "0\n";
      }
      else {
        cout << pq.top() << "\n";
        pq.pop();
      }
    }
    else {
      pq.push(num);
    }
  }

  return 0;
}

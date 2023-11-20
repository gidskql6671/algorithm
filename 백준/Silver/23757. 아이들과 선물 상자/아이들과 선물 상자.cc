#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, m;
  cin >> n >> m;

  priority_queue<int> pq;
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;

    pq.push(num);
  }

  bool isFailed = false;
  for(int i = 0; i < m; i++) {
    int requiredNum;
    cin >> requiredNum;

    if (pq.top() < requiredNum) {
      isFailed = true;

      break;
    }

    pq.push(pq.top() - requiredNum);
    pq.pop();
  }

  cout << (isFailed ? 0 : 1) << endl;

  return 0;
}

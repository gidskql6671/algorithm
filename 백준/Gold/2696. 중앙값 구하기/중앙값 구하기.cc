#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;

  while(T--) {
    int n;
    cin >> n;
    cout << (n + 1) / 2 << "\n";

    priority_queue<int> maxHeap; // mid보다 작은 값이 들어감
    priority_queue<int, vector<int>, greater<int>> minHeap; // mid보다 큰 값이 들어감

    int mid, i;
    for(i = 0; i < n; i++) {
      int num;
      cin >> num;

      if (i == 0) {
        mid = num;
      }
      else if (num < mid) {
        maxHeap.push(num);
      }
      else {
        minHeap.push(num);
      }

      if (i % 2 == 0) {
        while(minHeap.size() < maxHeap.size()) {
          minHeap.push(mid);
          mid = maxHeap.top();
          maxHeap.pop();
        }
        while(minHeap.size() > maxHeap.size()) {
          maxHeap.push(mid);
          mid = minHeap.top();
          minHeap.pop();
        }

        cout << mid << " ";
        if ((i + 2) % 20 == 0) {
          cout << "\n";
        }
      }
    }

    if ((i + 2) % 20 > 1) {
      cout << "\n";
    }
  }

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int result = arr[0];
  stack<int> s;
  s.push(0);
  for(int i = 1; i < n; i++) {
    if (arr[s.top()] < arr[i]) {
      s.push(i);
      continue;
    }

    while(not s.empty() && arr[s.top()] > arr[i]) {
      int height = arr[s.top()];
      s.pop();

      if (s.empty()) {
        result = max(result, height * i);
      }
      else {
        result = max(result, height * (i - s.top() - 1));
      }
    }

    s.push(i);
  }

  while(not s.empty()) {
    int height = arr[s.top()];
    s.pop();

    if (s.empty()) {
      result = max(result, height * n);
    }
    else {
      result = max(result, height * (n - s.top() - 1));
    }
  }

  cout << result << endl;

  return 0;
}

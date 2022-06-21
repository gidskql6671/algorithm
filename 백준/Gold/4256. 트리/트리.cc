#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

int preOrder[1001], inOrder[1001];

void daq(int start, int end, int root) {
  for(int i = start; i < end; i++) {
    if (inOrder[i] == preOrder[root]) {
      int leftTreeSize = i - start + 1;

      daq(start, i, root + 1);
      daq(i + 1, end, root + leftTreeSize);
      cout << preOrder[root] << " ";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> inOrder[i];
    }

    daq(0, n, 0);

    cout << "\n";
  }

  return 0;
}

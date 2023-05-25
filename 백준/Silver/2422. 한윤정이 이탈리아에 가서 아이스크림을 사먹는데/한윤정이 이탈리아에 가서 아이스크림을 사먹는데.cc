#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


bool isPossible[201][201];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      isPossible[i][j] = true;
    }
  }

  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    isPossible[a][b] = false;
    isPossible[b][a] = false;
  }

  int count = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      if (not isPossible[i][j]) {
        continue;
      }

      for(int k = j + 1; k <= n; k++) {
        if (not isPossible[i][k] or not isPossible[j][k]) {
          continue;
        }

        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}

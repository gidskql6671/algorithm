#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, v;
  cin >> n;

  int counts[201] = {0};
  for(int i = 0; i < n; i++) {
    cin >> v;

    counts[v + 100]++;
  }

  cin >> v;

  cout << counts[v + 100] << endl;

  return 0;
}
#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


void multipleMatrix(ll a[][2], ll b[][2], ll result[][2]) {
  ll tmp[][2] = {{0, 0}, {0, 0}};

  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        tmp[i][j] += a[i][k] * b[k][j] % 1000000007;
      }

      result[i][j] = tmp[i][j];
    }
  }
}

void solve(ll a[][2], ll n, ll result[][2]) {
  if (n == 1) {
    result[0][0] = a[0][0];
    result[0][1] = a[0][1];
    result[1][0] = a[1][0];
    result[1][1] = a[1][1];

    return;
  }

  ll tmp[2][2];
  solve(a, n / 2, tmp);
  if (n % 2) {
    ll tmpResult[2][2];
    multipleMatrix(tmp, tmp, tmpResult);
    multipleMatrix(tmpResult, a, result);
  }
  else {
    multipleMatrix(tmp, tmp, result);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  ll n;
  cin >> n;

  ll matrix[][2] = {{1, 1}, {1, 0}}, result[2][2];
  solve(matrix, n, result);

  cout << result[0][1] % 1000000007 << endl;

  return 0;
}

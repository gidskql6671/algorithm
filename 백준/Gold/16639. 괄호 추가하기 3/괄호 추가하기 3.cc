#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int dp_max[19][19];
int dp_min[19][19];

int calculate(int a, int b, char oper) {
  if (oper == '+') {
    return a + b;
  } else if (oper == '-') {
    return a - b;
  } else {
    return a * b;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  string str;
  cin >> str;

  for(int i = 0; i < 19; i++) {
    for(int j = 0; j < 19; j++) {
      dp_max[i][j] = INT_MIN;
      dp_min[i][j] = INT_MAX;
    }
  }

  for(int i = 0; i < n; i += 2) {
    dp_max[i][i] = dp_min[i][i] = str[i] - '0';
  }

  for(int i = 2; i < n; i += 2) {
    for(int j = 0; j < n - i; j += 2) {
      for(int k = 2; k <= i; k += 2) {
        int t1 = calculate(dp_min[j][j + k - 2], dp_min[j + k][i + j], str[j + k - 1]);
        int t2 = calculate(dp_min[j][j + k - 2], dp_max[j + k][i + j], str[j + k - 1]);
        int t3 = calculate(dp_max[j][j + k - 2], dp_min[j + k][i + j], str[j + k - 1]);
        int t4 = calculate(dp_max[j][j + k - 2], dp_max[j + k][i + j], str[j + k - 1]);

        dp_max[j][i + j] = max(dp_max[j][i + j], max(t1, max(t2, max(t3, t4))));
        dp_min[j][i + j] =  min(dp_min[j][i + j], min(t1, min(t2, min(t3, t4))));
      }
    }
  }

  cout << dp_max[0][n - 1] << endl;

  return 0;
}

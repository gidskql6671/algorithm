#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


ll convertNotation(string num, int notation) {
  ll result = 0;
  ll mul = 1;

  reverse(num.begin(), num.end());
  for(char c : num) {
    int curVal;
    if ('0' <= c and c <= '9') {
      curVal = c - '0';
    }
    else {
      curVal = c - 'a' + 10;
    }

    if (curVal >= notation) {
      return -1;
    }

    if (LONG_MAX - curVal * mul < result) {
      return -1;
    }

    result += curVal * mul;
    mul *= notation;
  }

  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  string a, b;
  cin >> a >> b;

  int result = -1, A, B;
  for(int i = 2; i <= 36; i++) {
    for(int j = 2; j <= 36; j++) {
      if (i == j) {
        continue;
      }

      ll result1 = convertNotation(a, i);
      ll result2 = convertNotation(b, j);

      if (result1 == result2 && result1 != -1) {
        if (result != -1) {
          cout << "Multiple\n";

          return 0;
        }
        result = result1;
        A = i;
        B = j;
      }
    }
  }

  if (result == -1) {
    cout << "Impossible\n";
  }
  else {
    cout << result << " " << A << " " << B << endl;
  }

  return 0;
}

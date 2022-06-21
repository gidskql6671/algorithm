#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, k;
  cin >> n >> k;

  string number;
  cin >> number;

  int deletedCount = 0;
  stack<char> frontChars;
  for(int i = 0; i < n;) {
    char currentChar = number[i];

    if (deletedCount == k || frontChars.empty()) {
      frontChars.push(currentChar);
      i++;
      continue;
    }

    char frontChar = frontChars.top();
    if (frontChar < currentChar) {
      frontChars.pop();
      deletedCount++;
    }
    else {
      frontChars.push(currentChar);
      i++;
    }
  }

  while (deletedCount < k) {
    frontChars.pop();
    deletedCount++;
  }

  string result = "";
  while (!frontChars.empty()) {
    result += frontChars.top();
    frontChars.pop();
  }
  reverse(result.begin(), result.end());
  cout << result << endl;

  return 0;
}

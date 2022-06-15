#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

int gcd(int a, int b) {
  if (a < b) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int gcdValue = abs(arr[1] - arr[0]);
  for(int i = 2; i < n; i++) {
    gcdValue = gcd(gcdValue, abs(arr[i] - arr[i - 1]));
  }

  set<int> result;
  for(int i = 2; i <= sqrt(gcdValue); i++) {
    if (gcdValue % i == 0) {
      result.insert(i);
      result.insert(gcdValue / i);
    }
  }
  result.insert(gcdValue);

  for(int value : result) {
    cout << value << " ";
  }

  return 0;
}

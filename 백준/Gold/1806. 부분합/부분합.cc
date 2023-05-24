#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[100001], acuSum[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, s;
  cin >> n >> s;

  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    acuSum[i] = acuSum[i - 1] + arr[i];
  }

  int l = 1, r = 1;
  int minLength = INF, curSum = 0;
  while(true) {
    if (curSum < s) {
      if (r > n) {
        break;
      }

      curSum += arr[r];
      r++;
    }
    else {
      minLength = min(minLength, r - l);

      curSum -= arr[l];
      l++;
    }
  }

  cout << (minLength == INF ? 0 : minLength) << endl;

  return 0;
}

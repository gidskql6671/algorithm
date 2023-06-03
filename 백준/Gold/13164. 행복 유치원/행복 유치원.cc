#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[300001], diff[300001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, k;
  cin >> n >> k;

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for(int i = 0; i < n - 1; i++) {
    diff[i] = arr[i + 1] - arr[i];
  }
  sort(diff, diff + n - 1);

  int result = 0;
  for(int i = 0; i < n - k; i++) {
    result += diff[i];
  }

  cout << result << endl;

  return 0;
}

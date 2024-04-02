#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int arr[10000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;

  while(T--) {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort(arr, arr + n);

    int diff = arr[1] - arr[0];
    for(int i = 1; i < n; i += 2) {
      if (i + 2 < n) {
        diff = max(diff, arr[i + 2] - arr[i]);
      }
      else if (i + 1 < n) {
        diff = max(diff, arr[i + 1] - arr[i]);
      }
      else {
        break;
      }
    }

    diff = max(diff, arr[2] - arr[0]);
    for(int i = 2; i < n; i += 2) {
      if (i + 2 < n) {
        diff = max(diff, arr[i + 2] - arr[i]);
      }
      else if (i + 1 < n) {
        diff = max(diff, arr[i + 1] - arr[i]);
      }
      else {
        break;
      }
    }

    cout << diff << endl;
  }

  return 0;
}

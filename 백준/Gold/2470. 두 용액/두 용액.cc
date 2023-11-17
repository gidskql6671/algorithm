#include <bits/stdc++.h>
#define INF 2000000000
typedef long long ll;

using namespace std;


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
  sort(arr.begin(), arr.end());

  int i = 0, j = n - 1;
  int best = INF;
  int bestI, bestJ;
  while(i < j) {
    int sum = abs(arr[i] + arr[j]);
    if (sum < best) {
      best = sum;
      bestI = arr[i];
      bestJ = arr[j];
    }

    if (arr[i] + arr[j] < 0) {
      i++;
    }
    else if (arr[i] + arr[j] > 0) {
      j--;
    }
    else {
      bestI = arr[i];
      bestJ = arr[j];
      break;
    }
  }

  cout << bestI << " " << bestJ << endl;

  return 0;
}

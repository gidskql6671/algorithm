#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int arr[3];
  cin >> arr[0] >> arr[1] >> arr[2];

  sort(arr, arr + 3);

  int minsSum = arr[0] + arr[1];
  if (arr[2] < minsSum) {
    cout << minsSum + arr[2] << endl;
  }
  else {
    cout << minsSum + minsSum - 1 << endl;
  }

  return 0;
}
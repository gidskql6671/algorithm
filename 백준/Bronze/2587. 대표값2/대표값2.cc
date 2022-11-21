#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  vector<int> arr(5);
  int sum = 0;
  for(int i = 0; i < 5; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  sort(arr.begin(), arr.end());

  cout << sum / 5 << "\n" << arr[2] << "\n";

  return 0;
}
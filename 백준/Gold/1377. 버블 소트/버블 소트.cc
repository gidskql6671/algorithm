#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


pair<int, int> arr[500001];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr, arr + n);

  int maxDiff = -1;
  for(int i = 0; i < n; i++) {
    maxDiff = max(maxDiff, arr[i].second - i);
  }

  cout << maxDiff + 1 << endl;

  return 0;
}
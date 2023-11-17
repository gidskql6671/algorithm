#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int n, s;
int arr[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int result = INF, i = 0, j = 0, sum = arr[0];
  while(i <= j and j < n) {
    if (sum >= s) {
      result = min(result, j - i + 1);

      sum -= arr[i];
      i++;
    }
    else {
      j++;
      sum += arr[j];
    }
  }

  cout << (result == INF ? 0 : result) << endl;

  return 0;
}

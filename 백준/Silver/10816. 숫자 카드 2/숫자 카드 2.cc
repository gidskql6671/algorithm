#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[500001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int n, m;

	cin >> n;

	for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
	sort(arr, arr + n);

	cin >> m;

	for (int i = 0; i < m; i++) {
		int x;
    cin >> x;

    cout << upper_bound(arr, arr + n, x) - lower_bound(arr, arr + n, x) << " ";
	}
  cout << endl;

  return 0;
}

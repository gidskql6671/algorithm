#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[11];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int n, k, count = 0;

  cin >> n >> k;

	for (int i = 0; i < n; i++) {
    cin >> arr[i];
	}

	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; i++) {
		if (k >= arr[i]) {
			count += k / arr[i];
			k %= arr[i];
		}
	}

  cout << count << endl;

  return 0;
}
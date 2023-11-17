#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[1000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int n, m;
  cin >> n >> m;

	for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
	sort(arr, arr + n, greater<int>());

	int left = 0, right = arr[0]; // right는 가장 큰 나무의 길이
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		ll sum = 0;

		for (int i = 0; i < n; i++) {
			if (mid >= arr[i]) {
				break;
      }

			sum += arr[i] - mid;
		}

		if (sum > m) {
			ans = mid;
			left = mid + 1;
		}
		else if (sum < m) {
			right = mid - 1;
    }
		else {
      cout << mid << "\n";

			return 0;
		}
	}

  cout << ans << endl;

  return 0;
}

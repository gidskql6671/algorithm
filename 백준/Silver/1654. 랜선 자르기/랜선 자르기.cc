#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[10000];

int main() {
	long long left = 0,right = LLONG_MAX;

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		scanf("%d", &arr[i]);
	}

	int save = 0;
	while (left <= right) {
		long long sum = 0, mid = (left+right)/2;
		for (int i = 0; i < k; i++) {
			sum += arr[i] / mid;
		}
		if (sum < n) {
			right = mid - 1;
		}
		else if (sum >= n) {
			if (save < mid)
				save = mid;
			left = mid + 1;
		}
	}
	printf("%d\n", save);

	return 0;
}

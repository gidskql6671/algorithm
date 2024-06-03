#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <functional>
using namespace std;

int main() {
	int n, arr[50];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	printf("%d\n", arr[0] * arr[n - 1]);

	return 0;
}
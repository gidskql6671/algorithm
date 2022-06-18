#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long DP[101];

int main() {
	int t, n;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int i = 1; i <= 3; i++)
			DP[i] = 1;
		for (int i = 4; i <= n; i++)
			DP[i] = DP[i - 3] + DP[i - 2];
		printf("%lld\n", DP[n]);
	}

	return 0;
}
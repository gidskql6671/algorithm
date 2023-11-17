#include <iostream>
#include <cstdio>
using namespace std;

int map[100001];
int DP[100001];

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &map[i]);
	
	DP[1] = map[1];
	for (int i = 2; i <= n; i++) {
		DP[i] = DP[i - 1] + map[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b, sum = 0;
		scanf("%d %d", &a, &b);

		printf("%d\n", DP[b] - DP[a-1]);
	}

	return 0;
}
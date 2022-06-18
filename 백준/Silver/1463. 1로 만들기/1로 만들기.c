#include <stdio.h>

int DP[1000001];
int main() {
	int num, i;

	scanf("%d", &num);

	DP[1] = 0;
	for (i = 2; i <= num; i++) {
		DP[i] = DP[i - 1] + 1;
		if (!(i % 2) && DP[i] > DP[i / 2] + 1)
			DP[i] = DP[i / 2] + 1;
		if (!(i % 3) && DP[i] > DP[i / 3] + 1)
			DP[i] = DP[i / 3] + 1;
	}
	printf("%d\n", DP[num]);


	return 0;
}
#include <stdio.h>

int dp[10001];
int main()
{
	int n, coin, k;

	dp[0] = 1; // 0원을 만드는 경우는 오직 1
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin);
		for (int j = 1; j <= k; j++) // j == 1 ~ j = k 까지 반복
			if (j >= coin) // 코인이 j원보다 작거나 같으면
				dp[j] = dp[j] + dp[j - coin];
		//j원을 만드는 경우의 수에 (j-coin)원을 만드는 경우를 더해준다.
	}
	printf("%d", dp[k]);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int DB[41][2];

int main()
{
	int i,n,T;
	
	DB[0][0] = 1;
	DB[0][1] = 0;
	DB[1][0] = 0;
	DB[1][1] = 1;

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (i = 2; i <= n; i++) {
			DB[i][0] = DB[i - 1][0] + DB[i - 2][0];
			DB[i][1] = DB[i - 1][1] + DB[i - 2][1];
		}
		printf("%d %d\n", DB[n][0], DB[n][1]);
	}

	return 0;
}

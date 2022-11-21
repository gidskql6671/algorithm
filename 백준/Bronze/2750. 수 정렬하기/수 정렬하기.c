#include <stdio.h>

int main() {
	int n, i, j, temp,input[1000];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &input[i]);
	for (i = 0; i < n; i++) 
		for (j=i;j<n;j++)
			if (input[i] > input[j]) {
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
	for (i = 0; i < n; i++)
		printf("%d\n", input[i]);

	return 0;
}
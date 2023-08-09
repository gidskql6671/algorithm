#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char A[4],B[4], temp;
	int a, b;

	scanf("%s", A);
	scanf("%s", B);

	temp = A[0];
	A[0] = A[2];
	A[2] = temp;

	temp = B[0];
	B[0] = B[2];
	B[2] = temp;

	a = atoi(A);
	b = atoi(B);

	(a > b) ? printf("%d\n", a) : printf("%d\n", b);

	return 0;
}

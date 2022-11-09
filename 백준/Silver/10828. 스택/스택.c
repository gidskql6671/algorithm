#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[10001];
int main() {
	int n, index = -1;
	char input[15];

	scanf("%d ", &n);

	for (int i = 0; i < n; i++) {
		gets(input);
		if (strstr(input, "top")) {
			if (index == -1)
				printf("-1\n");
			else
				printf("%d\n", stack[index]);
		}
		else if(strstr(input, "empty")) {
			if (index == -1)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strstr(input, "size")) {
			if (index == -1)
				printf("0\n");
			else
				printf("%d\n", index + 1);
		}
		else if (strstr(input, "pop")) {
			if (index == -1)
				printf("-1\n");
			else {
				printf("%d\n", stack[index]);
				stack[index--] = 0;
			}
		}
		else if (strstr(input, "push")) {
			strtok(input, " ");
			stack[++index] = atoi(strtok(NULL," "));
		}
	}
}
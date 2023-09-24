#include<stdio.h>

int main()
{
	int goal=0, num3=0, num5=0,OK=1;

	scanf("%d", &goal);
	
	if (goal % 5 == 0) {
		num5 = goal / 5;
		printf("%d", num5);
	}
	else {
		num5 = goal / 5;
		while (OK) {
			for(num3=1;(num3*3+num5*5)<=goal;num3++)
				if (goal == num5 * 5 + num3 * 3) {
					printf("%d", num3 + num5);
					OK = 0;
				}
			num5--;
			if (num5 == -1 && OK == 1) {
				printf("-1");
				break;
			}
		}
	}

	return 0;
}
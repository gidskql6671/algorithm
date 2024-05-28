#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;

	cin >> T;

	/*
		경우 1 : 완전히 똑같은 원 : -1
		경우 2 : 중심은 동일, 반지름이 다름 : 0
		경우 3 : 내접 : 1 
		경우 4 : 외접 : 1
		경우 5 : 밖에서 곂침 : 2
		경우 6 : 안에서 곂침 : 2
		경우 7 : 안에서 안곂침 : 0
		경우 8 : 밖에서 안곂침 : 0
	*/

	for (int t = 0; t < T; t++) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		double dis = sqrt(((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
		int rsum = r1 + r2;

		if (x1 == x2 && y1 == y2 && r1 == r2) {
			puts("-1");
		}
		else if (rsum == dis || dis + r1 == r2 || dis + r2 == r1) {
			puts("1");
		}
		else if (rsum < dis || dis + r1 < r2 || dis + r2 < r1) {
			puts("0");
		}
		else
			puts("2");


	}

	return 0;
}
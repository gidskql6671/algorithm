#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, T;

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int x1, y1, x2, y2;
		int Count = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		scanf("%d", &n);
		for (int i = 0; i < n; i++) { // 시작점 혹은 끝점 둘 중 한개만 원 안에 있어야 곂쳐서 지나감
			int tx, ty, r;
			scanf("%d %d %d", &tx, &ty, &r);
			double dis_start, dis_end;
			dis_start = sqrt(pow(x1 - tx, 2) + pow(y1 - ty, 2));
			dis_end = sqrt(pow(x2 - tx, 2) + pow(y2 - ty, 2));

			if ((dis_start > r && dis_end < r) || (dis_start < r && dis_end > r))
				Count++;
		}
		printf("%d\n", Count);
	}

	return 0;
}
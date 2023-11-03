#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n, tmp, sum = 0, result = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		sum += v[i];
		result += sum;
	}

	printf("%d\n", result);

	return 0;
}
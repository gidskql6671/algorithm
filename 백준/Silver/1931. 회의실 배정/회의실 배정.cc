#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

struct mycomp {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
};

int main() {
	int n, Count = 0, end, tmp1, tmp2;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		v.push_back(make_pair(tmp1, tmp2));
	}
	sort(v.begin(), v.end(), mycomp());

	Count++; end = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].first >= end) {
			end = v[i].second;
			Count++;
		}
	}

	printf("%d\n", Count);

	return 0;
}
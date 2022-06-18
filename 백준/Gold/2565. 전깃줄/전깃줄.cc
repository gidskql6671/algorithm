#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;

pair<int,int> arr[101];
vector<int> lis;

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = make_pair(a, b);
	}
	sort(arr, arr + n);

	lis.push_back(-INF);
	for (int i = 0; i < n; i++) {
		if (lis.back() < arr[i].second)
			lis.push_back(arr[i].second);
		else {
			auto iter = lower_bound(lis.begin(), lis.end(), arr[i].second);
			*iter = arr[i].second;
		}
	}

	printf("%d\n", n - lis.size() + 1);
	return 0;
}
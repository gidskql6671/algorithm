#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

vector<pair<int, int>> v;

struct mycmp {
	bool operator()(const pair<int, int> a, const pair<int, int> b) const {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


	int n, count = 0;

  cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp, tmp2;
    cin >> tmp >> tmp2;

		v.push_back({tmp, tmp2});
	}

	sort(v.begin(), v.end(), mycmp());

	int curTime = 0;
	for (int i = 0; i < n; i++) {
		if (curTime <= v[i].first) {
			curTime = v[i].second;
			count++;
		}
	}

  cout << count << endl;

  return 0;
}

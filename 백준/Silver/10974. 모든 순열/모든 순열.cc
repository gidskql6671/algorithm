#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


	int n;
  cin >> n;

  vector<int> arr;
	for (int i = 1; i <= n; i++) {
    arr.push_back(i);
  }

	do {
		for (int ele : arr) {
      cout << ele << " ";
    }
    cout << "\n";
	} while (next_permutation(arr.begin(), arr.end()));


	return 0;
}
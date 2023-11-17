#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[100001];
int DP[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


	int n, m;
  cin >> n >> m;

	for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

	DP[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		DP[i] = DP[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
    cin >> a >> b;

    cout << DP[b] - DP[a-1] << "\n";
	}

  return 0;
}

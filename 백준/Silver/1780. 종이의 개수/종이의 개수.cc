#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[3000][3000];
int ans[3];

void dac(int sx, int sy, int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int n;
  cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

	dac(0, 0, n);

	for (int i : ans) {
    cout << i << "\n";
  }

  return 0;
}

void dac(int sx, int sy, int n) {
	int stand = arr[sy][sx];
	bool div = false;

	for (int i = sy; i < sy + n; i++) {
		for (int j = sx; j < sx + n; j++) {
			if (stand != arr[i][j]) {
				div = true;
				break;
			}
		}
		if (div == true)
			break;
	}

	if (div) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				dac(sx + j * (n / 3), sy + i * (n / 3), n / 3);
      }
    }
	}
	else {
		ans[stand + 1] += 1;
	}
}
#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[100001];


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


	int n, m;
    cin >> n;

	for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
	sort(arr, arr + n);
    
    cin >> m;

	for (int i = 0; i < m; i++) {
		int num;
        cin >> num;

		int left = 0, right = n - 1;
		bool findNum = false;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] == num) {
				findNum = true;
				break;
			}
			else if (arr[mid] > num)
				right = mid - 1;
			else
				left = mid + 1;
		}

		if (findNum) {
            cout << "1\n";
        }
		else {
            cout << "0\n";            
        }
	}

  return 0;
}

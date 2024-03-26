#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int arr[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    int count = 0;
    for(int i = n - 1; i > 0; i--) {
      for(int j = 0; j < i; j++) {
        if (arr[j] > arr[j + 1]) {
          int tmp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = tmp;

          count++;
        }
      }
    }

    cout << count << endl;
  }

  return 0;
}

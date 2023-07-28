#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;

  while(T--) {
    int t;
    cin >> t;

    int arr[20];
    for(int i = 0; i < 20; i++) {
      cin >> arr[i];
    }

    int count = 0;
    for(int i = 1; i < 20; i++) {
      for(int j = i - 1; j >= 0; j--) {
        if (arr[j + 1] < arr[j]) {
          int tmp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = tmp;
          count++;
        }
        else {
          break;
        }
      }
    }

    cout << t << " " << count << "\n";
  }

  return 0;
}

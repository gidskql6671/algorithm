#include <bits/stdc++.h>
#define INF 987654321
#define MAX 1000000
typedef long long ll;

using namespace std;


bool isPrime[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  for(int i = 2; i <= MAX; i++) {
    isPrime[i] = true;
  }

  for(int i = 2; i <= MAX; i++) {
    if (isPrime[i] == 0) {
      continue;
    }

    for(int j = 2 * i; j <= MAX; j += i) {
      isPrime[j] = false;
    }
  }

  int T;
  cin >> T;

  while(T--) {
    int n;
    cin >> n;

    int count = 0;
    for(int i = 2; i <= n / 2; i++) {
      if (isPrime[i] && isPrime[n - i]) {
        count++;
      }
    }

    cout << count << endl;
  }

  return 0;
}
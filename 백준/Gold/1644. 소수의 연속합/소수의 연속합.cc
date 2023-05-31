#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


bool prime[4000001];

void initPrime() {
  int num = 4000000;

  for(int i = 2; i <= num; i++) {
    prime[i] = true;
  }

  for(int i = 2; i <= num; i++) {
    if (not prime[i]) {
      continue;
    }

    for(int j = i * 2; j <= num; j += i) {
      prime[j] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  initPrime();

  int n;
  cin >> n;

  int l = 0, r = 0;
  int sum = 0, count = 0;
  while(r <= 4000000 and l <= n) {
    if (sum == n) {
      count++;

      while(not prime[l]) {
        l++;
      }

      sum -= l++;
    }
    else if (sum < n) {
      while(r <= 4000000 and not prime[r]) {
        r++;
      }

      sum += r++;
    }
    else {
      while(l <= 4000000 and not prime[l]) {
        l++;
      }

      sum -= l++;
    }
  }

  cout << count << endl;

  return 0;
}

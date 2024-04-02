#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, k, bits[32] = {0};
  cin >> n >> k;

  int bitCount = 0, count1 = 0;
  while(n > 0) {
    bits[bitCount] = n % 2;
    if (bits[bitCount] == 1) {
      count1++;
    }
    bitCount++;

    n /= 2;
  }

  int result = 0, stand = 1, pos = 0;
  bool isPropagation = false;
  while(k < count1 or isPropagation) {
    if (isPropagation) {
      if (bits[pos] == 1) {
        bits[pos] = 0;
        count1--;
      }
      else {
        bits[pos] = 1;
        count1++;
        isPropagation = false;

        pos--;
        stand /= 2;
      }
    }
    else if (bits[pos] == 1) {
      bits[pos] = 0;
      count1--;
      result += stand;
      isPropagation = true;
    }

    pos++;
    stand *=2;
  }

  cout << result << endl;

  return 0;
}

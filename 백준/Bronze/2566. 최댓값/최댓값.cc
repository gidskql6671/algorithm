#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int y, x, num = -1, tmp;
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      cin >> tmp;

      if (tmp > num) {
        num = tmp;
        y = i;
        x = j;
      }
    }
  }

  cout << num << "\n"; 
  cout << y << " " << x << endl;

  return 0;
}
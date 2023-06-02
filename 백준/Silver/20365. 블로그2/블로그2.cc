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

  string str;
  cin >> str;

  int count1 = (str[0] == 'R' ? 2 : 1);
  for(int i = 1; i < n; i++) {
    if (str[i] == 'R' and str[i - 1] == 'B') {
      count1++;
    }
  }

  int count2 = (str[0] == 'B' ? 2 : 1);
  for(int i = 1; i < n; i++) {
    if (str[i] == 'B' and str[i - 1] == 'R') {
      count2++;
    }
  }

  cout << min(count1, count2) << endl;

  return 0;
}

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

  int count = 0;
  vector<int> cow(10, -1);
  for(int i = 0; i < n; i++) {
    int cowNum, pos;
    cin >> cowNum >> pos;
    cowNum--;

    if (cow[cowNum] == -1) {
      cow[cowNum] = pos;
      continue;
    }

    if (cow[cowNum] != pos) {
      cow[cowNum] = pos;
      count++;
    }
  }

  cout << count << endl;

  return 0;
}

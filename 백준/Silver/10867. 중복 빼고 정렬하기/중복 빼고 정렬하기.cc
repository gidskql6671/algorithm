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

  set<int> s;
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;

    s.insert(num);
  }

  for(int ele : s) {
    cout << ele << " ";
  }
  cout << endl;

  return 0;
}

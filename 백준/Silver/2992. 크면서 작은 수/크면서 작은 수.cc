#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  string x;
  cin >> x;

  bool isEnd = not next_permutation(x.begin(), x.end());

  if (isEnd) {
    cout << 0 << endl;
  }
  else {
    cout << x << endl;
  }

  return 0;
}
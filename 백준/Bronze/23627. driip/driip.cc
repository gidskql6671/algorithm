#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  string str;
  cin >> str;

  string pattern = "driip";
  int j = pattern.size() - 1;
  for(int i = str.size() - 1; i >= 0 and j >= 0; i--, j--) {
    if (str[i] != pattern[j]) {
      cout << "not cute\n";
      return 0;
    }
  }

  if (j == -1) {
    cout << "cute\n";
  }
  else {
    cout << "not cute\n";
  }

  return 0;
}

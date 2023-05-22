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

  char diff = 'a' - 'A';
  for(char c : str) {
    if ('a' <= c and c <= 'z') {
      cout << (char)(c - diff);
    }
    else {
      cout << (char)(c + diff);
    }
  }
  cout << endl;

  return 0;
}

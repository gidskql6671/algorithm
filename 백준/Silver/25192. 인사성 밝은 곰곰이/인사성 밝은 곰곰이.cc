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
  set<string> s;
  for(int i = 0; i < n; i++) {
    string chat;
    cin >> chat;

    if (chat == "ENTER") {
      s.clear();
    }
    else if (s.count(chat) == 0) {
      s.insert(chat);
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
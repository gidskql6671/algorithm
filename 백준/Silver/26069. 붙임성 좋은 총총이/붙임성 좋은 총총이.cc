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

  set<string> s;
  s.insert("ChongChong");
  for(int i = 0; i < n; i++) {
    string name1, name2;
    cin >> name1 >> name2;

    if (s.count(name1) > 0 | s.count(name2) > 0) {
      s.insert(name1);
      s.insert(name2);
    }
  }

  cout << s.size() << endl;

  return 0;
}
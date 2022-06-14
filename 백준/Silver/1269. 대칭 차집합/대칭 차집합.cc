#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  set<int> a, b;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;

    a.insert(tmp);
  }

  for(int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;

    b.insert(tmp);
  }

  int count = 0;
  auto iter1 = a.begin(), iter2 = b.begin();
  while(iter1 != a.end() && iter2 != b.end()) {
    if (*iter1 == *iter2) {
      iter1++;
      iter2++;
    }
    else if (*iter1 < *iter2) {
      count++;
      iter1++;
    }
    else {
      count++;
      iter2++;
    }
  }

  while(iter1 != a.end()) {
      count++;
      iter1++;
  }

  while(iter2 != b.end()) {
      count++;
      iter2++;
  }

  cout << count << endl;

  return 0;
}

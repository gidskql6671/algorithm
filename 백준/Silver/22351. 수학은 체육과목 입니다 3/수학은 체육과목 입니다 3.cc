#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

int getEnd(string str, int start) {
  int cur = start;

  int i = 0;
  while(i < str.length()) {
    string sCur = to_string(cur);

    if (sCur == str.substr(i, sCur.length())) {
      i += sCur.length();
      cur++;
    }
    else {
      return -1;
    }
  }

  return cur - 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  string str;
  cin >> str;

  int start, end;
  for (int i = 1; i <= 3; i++) {
    start = stoi(str.substr(0, i));

    end = getEnd(str, start);
    if (end >= start) {
      break;
    }
  }

  cout << start << " " << end << endl;

  return 0;
}

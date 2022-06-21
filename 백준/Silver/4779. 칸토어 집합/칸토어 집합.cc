#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

vector<string> results;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  results.push_back("-");
  for(int i = 1; i <= 12; i++) {
    string prevStr = results[i - 1];
    string spaceStr((int) pow(3, i - 1), ' ');
    string str = prevStr + spaceStr + prevStr;

    results.push_back(str);
  }

  while(true) {
    int n;
    cin >> n;
    if (cin.eof()) {
      break;
    }

    cout << results[n] << "\n";
  }

  return 0;
}

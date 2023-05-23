#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


string names[101];
bool visited[101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int tc = 1;
  while(true) {
    int n;
    cin >> n;

    if (n == 0) {
      break;
    }

    getline(cin, names[0]); // 버퍼 공백문자 제거
    for(int i = 1; i <= n; i++) {
      getline(cin, names[i]);

      visited[i] = false;
    }

    for(int i = 0; i < 2 * n - 1; i++) {
      int num;
      string tmp;
      cin >> num >> tmp;

      visited[num] = not visited[num];
    }

    for(int i = 1; i <= n; i++) {
      if (visited[i]) {
        cout << tc << " " << names[i] << endl;
        break;
      }
    }

    tc++;
  }

  return 0;
}

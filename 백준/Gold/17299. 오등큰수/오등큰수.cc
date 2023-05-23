#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n;
int arr[1000001], counts[1000001], ngf[1000001];
stack<pair<int, int>> s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    counts[arr[i]]++;
    ngf[i] = -1;
  }

  for(int i = 0; i < n; i++) {
    int curNum = arr[i];
    int countOfCurNum = counts[curNum];

    while(not s.empty() and s.top().second < countOfCurNum) {
      ngf[s.top().first] = curNum;
      s.pop();
    }

    s.push({i, countOfCurNum});
  }

  for(int i = 0; i < n; i++) {
    cout << ngf[i] << " ";
  }
  cout << endl;

  return 0;
}

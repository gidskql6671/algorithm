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

  map<string, int> wordMap;
  for(int i = 0; i < n; i++) {
    string word;

    cin >> word;

    if (word.length() >= m) {
      wordMap[word] = wordMap[word] + 1;
    }
  }

  vector<tuple<int, int, string>> arr;
  for(auto iter : wordMap) {
    arr.push_back({-iter.second, -iter.first.length(), iter.first});
  }

  sort(arr.begin(), arr.end());

  for(int i = 0; i < arr.size(); i++) {
    cout << get<2>(arr[i]) << "\n";
  }

  return 0;
}
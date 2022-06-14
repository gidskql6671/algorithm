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

  vector<int> positions(n);
  set<int> uniquePositions;
  for(int i = 0; i < n; i++) {
    cin >> positions[i];
    uniquePositions.insert(positions[i]);
  }

  vector<int> sortedPostions;
  for(auto pos : uniquePositions) {
    sortedPostions.push_back(pos);
  }

  for(int i = 0; i < n; i++) {
    int compressedPosition = lower_bound(sortedPostions.begin(), sortedPostions.end(), positions[i]) - sortedPostions.begin();

    cout << compressedPosition << " ";
  }

  return 0;
}

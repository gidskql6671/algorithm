#include <bits/stdc++.h>
#define INF 987654321012L
typedef long long ll;
using namespace std;


map<string, string> group;
map<string, int> groupSize;

string root(string node) {
  while(node != group[node]) {
    node = group[node];
  }

  return node;
}

int unionGroup(string a, string b) {
  string aRoot = root(a), bRoot = root(b);

  if (aRoot == bRoot) {
    return groupSize[aRoot];
  }

  int result = 0;
  if (groupSize[aRoot] < groupSize[bRoot]) {
    groupSize[bRoot] += groupSize[aRoot];
    group[aRoot] = bRoot;
    result = groupSize[bRoot];
  }
  else {
    groupSize[aRoot] += groupSize[bRoot];
    group[bRoot] = aRoot;
    result = groupSize[aRoot];
  }

  return result;
}

bool isSameGroup(string a, string b) {
  string aRoot = root(a), bRoot = root(b);

  return aRoot == bRoot;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;
  while(T--) {
    group.clear();
    groupSize.clear();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
      string a, b;
      cin >> a >> b;

      if (group.find(a) == group.end()) {
        group[a] = a;
        groupSize[a] = 1;
      }
      if (group.find(b) == group.end()) {
        group[b] = b;
        groupSize[b] = 1;
      }

      cout << unionGroup(a, b) << "\n";
    }
  }

  return 0;
}

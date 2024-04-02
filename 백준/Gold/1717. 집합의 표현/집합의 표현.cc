#include <bits/stdc++.h>
#define INF 987654321012L
typedef long long ll;
using namespace std;


int n, m;
int groupSize[1000001], group[1000001];

int root(int node) {
  while(node != group[node]) {
    node = group[node];
  }

  return node;
}

void unionGroup(int a, int b) {
  int aRoot = root(a), bRoot = root(b);

  if (aRoot == bRoot) {
    return;
  }
  if (groupSize[aRoot] < groupSize[bRoot]) {
    groupSize[bRoot] += groupSize[aRoot];
    group[aRoot] = bRoot;
  }
  else {
    groupSize[aRoot] += groupSize[bRoot];
    group[bRoot] = aRoot;
  }
}

bool isSameGroup(int a, int b) {
  int aRoot = root(a), bRoot = root(b);

  return aRoot == bRoot;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    group[i] = i;
    groupSize[i] = 1;
  }

  for(int i = 0; i < m; i++) {
    int type, a, b;
    cin >> type >> a >> b;

    if (type == 0) {
      unionGroup(a, b);
    }
    else {
      cout << (isSameGroup(a, b) ? "YES" : "NO") << "\n";
    }
  }

  return 0;
}

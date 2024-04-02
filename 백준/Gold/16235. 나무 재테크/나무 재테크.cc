#include <bits/stdc++.h>
#define INF 987654321012L
typedef long long ll;
using namespace std;


int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, targetYear;
int feed[10][10], ground[10][10];
vector<pair<int, bool>> trees[10][10];

void spring() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = trees[i][j].size() - 1; k >= 0; k--) {
        if (ground[i][j] >= trees[i][j][k].first) {
          ground[i][j] -= trees[i][j][k].first;
          trees[i][j][k].first++;
        }
        else {
          trees[i][j][k].second = false;
        }
      }
    }
  }
}

void summer() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int k;
      for(k = 0; k < trees[i][j].size(); k++) {
        if (trees[i][j][k].second) {
          break;
        }

        ground[i][j] += trees[i][j][k].first / 2;
      }

      if (k > 0) {
        trees[i][j].erase(trees[i][j].begin(), trees[i][j].begin() + k);
      }
    }
  }
}

bool isInside(int y, int x) {
  return 0 <= y and y < n and 0 <= x and x < n;
}

void propagation(int y, int x) {
  for(int i = 0; i < 8; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (isInside(ny, nx)) {
      trees[ny][nx].push_back({1, true});
    }
  }
}

void fall() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < trees[i][j].size(); k++) {
        if (trees[i][j][k].first % 5 == 0) {
          propagation(i, j);
        }
      }
    }
  }
}

void winter() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      ground[i][j] += feed[i][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> m >> targetYear;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> feed[i][j];
      ground[i][j] = 5;
    }
  }

  for(int i = 0; i < m; i++) {
    int y, x, age;
    cin >> y >> x >> age;

    trees[y - 1][x - 1].push_back({age, true});
  }

  while(targetYear--) {
    spring();
    summer();
    fall();
    winter();
  }

  int result = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      result += trees[i][j].size();
    }
  }

  cout << result << endl;

  return 0;
}

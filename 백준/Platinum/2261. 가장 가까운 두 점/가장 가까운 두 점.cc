#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

int n;
pair<int, int> arr[100001];

int findMinDistUsingDaC(int left, int right);
int findMinDistUsingBF(int left, int right);
int findMinDistOfMid(int left, int right, int minDist);
int dist(pair<int, int> a, pair<int, int> b);

bool compareUsingX(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;


  for(int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr, arr + n);

  cout << findMinDistUsingDaC(0, n - 1) << endl;

  return 0;
}

int findMinDistUsingDaC(int left, int right) {
  if (right - left < 3) {
    // 범위에 속한 원소 개수가 3개 이하
    return findMinDistUsingBF(left, right);
  }

  int mid = (left + right) / 2;

  int minDist = min(findMinDistUsingDaC(left, mid), findMinDistUsingDaC(mid + 1, right));

  minDist = min(minDist, findMinDistOfMid(left, right, minDist));

  return minDist;
}

int findMinDistUsingBF(int left, int right) {
  if (left >= right) {
    return INF;
  }

  int minDist = INF;
  for(int i = left; i <= right; i++) {
    for(int j = i + 1; j <= right; j++) {
      minDist = min(minDist, dist(arr[i], arr[j]));
    }
  }

  return minDist;
}

int findMinDistOfMid(int left, int right, int minDist) {
  int mid = (left + right) / 2;

  vector<pair<int, int>> candidates;
  for(int i = left; i <= right; i++) {
    int yDist = arr[mid].first - arr[i].first;
    if (yDist * yDist < minDist) {
      candidates.push_back(arr[i]);
    }
  }

  sort(candidates.begin(), candidates.end(), compareUsingX);

  for(int i = 0; i < candidates.size(); i++) {
    pair<int, int> cur = candidates[i];
    for(int j = i + 1; j < candidates.size(); j++) {
      pair<int, int> other = candidates[j];

      int xDist = other.second - cur.second;
      if (xDist * xDist < minDist) {
        minDist = min(minDist, dist(cur, other));
      }
      else {
        break;
      }
    }
  }

  return minDist;
}

int dist(pair<int, int> a, pair<int, int> b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
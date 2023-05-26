#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n;
vector<int> arr, result;

int solve(int cur, int index) {
  int leftChild = cur * 2;
  int rightChild = cur * 2 + 1;

  if (leftChild < arr.size()) {
    index = solve(leftChild, index);
  }

  result[cur] = arr[index];
  index++;

  if (rightChild < arr.size()) {
    index = solve(rightChild, index);
  }

  return index;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;
  arr.assign(pow(2, n), 0);
  result.assign(pow(2, n), 0);

  for(int i = 1; i < arr.size(); i++) {
    cin >> arr[i];
  }

  solve(1, 1);

  int stand = 2;
  for(int i = 1; i < result.size(); i++) {
    cout << result[i] << " ";

    if (stand - 1 == i) {
      cout << "\n";
      stand *= 2;
    }
  }

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n;
vector<int> arr;
vector<int> operation;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;
  for(int i = 1; i <= n; i++) {
    int num;
    cin >> num;

    arr.push_back(i);
    operation.push_back(num);
  }

  deque<int> result;
  for(int i = n - 1, j = 0; i >= 0; i--, j++) {
    if (operation[i] == 1) {
      result.push_front(arr[j]);
    }
    else if (operation[i] == 2) {
      result.insert(result.begin() + 1, arr[j]);
    }
    else {
      result.push_back(arr[j]);
    }
  }

  for(int i = 0 ; i <  n; i++) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}

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

  vector<int> arr(n);
  int sum = 0;
  int numbers[8001] = {};
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
    numbers[arr[i] + 4000]++;
  }

  cout << floor((double) sum / n + 0.5) << endl;

  sort(arr.begin(), arr.end());
  cout << arr[n / 2] << endl;

  int mode1 = -1, mode2 = -1, maxCount = 0;
  for(int i = 0; i <= 8000; i++) {
    if (maxCount < numbers[i]) {
      maxCount = numbers[i];
      mode1 = i;
      mode2 = -1;
    }
    else if (maxCount == numbers[i]) {
      if (mode1 == -1) {
        mode1 = i;
      }
      else if (mode2 == -1) {
        mode2 = i;
      }
    }
  }

  cout << (mode2 == -1 ? mode1 : mode2) - 4000 << endl;
  cout << arr.back() - arr.front() << endl;

  return 0;
}

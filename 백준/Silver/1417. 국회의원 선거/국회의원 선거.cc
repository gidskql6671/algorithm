#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


string names[101];
bool visited[101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  int arr[51];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int count = 0;
  while(true) {
    int maxVal = -1, maxIndex = -1;
    for(int i = 0; i < n; i++) {
      if (maxVal <= arr[i]) {
        maxVal = arr[i];
        maxIndex = i;
      }
    }

    if (maxIndex == 0) {
      cout << count << endl;
      break;
    }

    count++;
    arr[maxIndex]--;
    arr[0]++;
  }

  return 0;
}

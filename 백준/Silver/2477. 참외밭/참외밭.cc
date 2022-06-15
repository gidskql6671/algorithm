#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int countPerSquareMeter;
  cin >> countPerSquareMeter;

  int largeWidth = 0, largeHeight = 0;
  vector<int> arr;
  for(int i = 0; i < 6; i++) {
    int dir, length;
    cin >> dir >> length;
    arr.push_back(length);

    if (dir == 1 || dir == 2) {
      largeWidth = max(largeWidth, length);
    }
    else {
      largeHeight = max(largeHeight, length);
    }
  }

  int i;
  for(i = 0; i < 5; i++) {
    if (arr[i] == largeWidth && arr[i + 1] == largeHeight) {
      break;
    }
    else if (arr[i] == largeHeight && arr[i + 1] == largeWidth) {
      break;
    }
  }

  int smallLength1 = arr[(i + 3) % 6];
  int smallLength2 = arr[(i + 4) % 6];

  int area = (largeWidth * largeHeight) - (smallLength1 * smallLength2);
  cout << countPerSquareMeter * area << endl;

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

int arr[128][128];
int countPaper[2];

void daq(int startY, int startX, int length) {
  int baseColor = arr[startY][startX];

  bool isDiffColor = false;
  for (int y = startY; y < startY + length; y++) {
    for (int x = startX; x < startX + length; x++) {
      if (arr[y][x] != baseColor) {
        isDiffColor = true;
        break;
      }
    }
    if (isDiffColor) {
      break;
    }
  }

  if (isDiffColor) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        daq(startY + (i * length / 2), startX + (j * length / 2), length / 2);
      }
    }
  }
  else {
    countPaper[baseColor]++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  daq(0, 0, n);

  cout << countPaper[0] << endl << countPaper[1] << endl;

  return 0;
}

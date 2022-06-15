#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int width, height, standY, standX;

bool isInside(int y, int x) {
  if (standY <= y && y <= standY + height && standX <= x && x <= standX + width) {
    return true;
  }

  int radius = height / 2;
  int sy = (y - (standY + radius));
  int sx = (x - standX);
  if (sy * sy + sx * sx <= radius * radius) {
    return true;
  }

  sy = (y - (standY + radius));
  sx = (x - (standX + width));
  if (sy * sy + sx * sx <= radius * radius) {
    return true;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int p;
  cin >> width >> height >> standX >> standY >> p;

  int count = 0;
  for(int i = 0; i < p; i++) {
    int x, y;
    cin >> x >> y;

    if (isInside(y, x)) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}

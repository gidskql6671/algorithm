#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[3][3] = {{0}};

int findWinner() {
  int winner = 0;

  for(int i = 0; i < 3; i++) {
    if (arr[i][0] > 0 and arr[i][0] == arr[i][1] and arr[i][1] == arr[i][2]) {
      return arr[i][0];
    }
    if (arr[0][i] > 0 and arr[0][i] == arr[1][i] and arr[1][i] == arr[2][i]) {
      return arr[0][i];
    }
  }

  if (arr[0][0] > 0 and arr[0][0] == arr[1][1] and arr[1][1] == arr[2][2]) {
    return arr[0][0];
  }
  if (arr[2][0] > 0 and arr[2][0] == arr[1][1] and arr[1][1] == arr[0][2]) {
    return arr[2][0];
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int order;
  cin >> order;

  int winner = 0;
  for(int i = 0; i < 9; i++) {
    int y, x;
    cin >> y >> x;

    arr[--y][--x] = order;

    winner = findWinner();
    if (winner > 0) {
      break;
    }

    order = order % 2 + 1;
  }

  cout << winner << endl;

  return 0;
}

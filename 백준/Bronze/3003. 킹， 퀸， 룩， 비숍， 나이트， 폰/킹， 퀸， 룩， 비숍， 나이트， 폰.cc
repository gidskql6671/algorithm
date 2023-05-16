#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int king, queen, rook, bishop, knight, pawn;

  cin >> king >> queen >> rook >> bishop >> knight >> pawn;

  cout << 1 - king << " ";
  cout << 1 - queen << " ";
  cout << 2 - rook << " ";
  cout << 2 - bishop << " ";
  cout << 2 - knight << " ";
  cout << 8 - pawn << "\n";

  return 0;
}
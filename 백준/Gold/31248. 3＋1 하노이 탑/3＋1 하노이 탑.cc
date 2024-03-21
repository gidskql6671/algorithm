#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


queue<string> moves;

void hanoi(int n, string from, string through, string to) {
  if (n <= 0) {
    return;
  }

  hanoi(n - 1, from, to, through);
  moves.push(from + " " + to);
  hanoi(n - 1, through, from, to);
}

void hanoi4(int n, string from, string through, string to) {
  if (n <= 0) {
    return;
  }
  else if (n == 1) {
    moves.push(from + " D");
    return;
  }

  hanoi(n - 2, from, through, to);
  moves.push(from + " " + through);
  moves.push(from + " D");
  moves.push(through + " D");
  hanoi4(n - 2, to, through, from);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  hanoi4(n, "A", "B", "C");

  cout << moves.size() << endl;
  while(not moves.empty()) {
    cout << moves.front() << "\n";
    moves.pop();
  }

  return 0;
}

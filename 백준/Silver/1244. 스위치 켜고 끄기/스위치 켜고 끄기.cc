#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

#define MAN 1
#define WOMAN 2


int n, m;
bool switches[101];

void applyMan(int stand) {
  for(int i = stand; i <= n; i += stand) {
    switches[i] = not switches[i];
  }
}

void applyWoman(int stand) {
  int i;
  for(i = 1; 0 < stand - i and stand + i <= n; i++) {
    if (switches[stand - i] != switches[stand + i]) {
      break;
    }
  }

  for(int j = stand - i + 1; j < stand + i; j++) {
    switches[j] = not switches[j];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> switches[i];
  }

  cin >> m;

  while(m--) {
    int type, num;
    cin >> type >> num;

    if (type == MAN) {
      applyMan(num);
    }
    else {
      applyWoman(num);
    }
  }

  for(int i = 1; i <= n; i++) {
    cout << switches[i] << " ";

    if (i % 20 == 0) {
      cout << "\n";
    }
  }

  return 0;
}

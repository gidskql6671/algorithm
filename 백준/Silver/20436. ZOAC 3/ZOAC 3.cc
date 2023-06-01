#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


pair<char, bool> board[3][10] = {
  {{'q', false}, {'w', false}, {'e', false}, {'r', false}, {'t', false}, {'y', true}, {'u', true}, {'i', true}, {'o', true}, {'p', true}},
  {{'a', false}, {'s', false}, {'d', false}, {'f', false}, {'g', false}, {'h', true}, {'j', true}, {'k', true}, {'l', true}},
  {{'z', false}, {'x', false}, {'c', false}, {'v', false}, {'b', true}, {'n', true}, {'m', true}}
};

pair<int, int> findPos(char c) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 10; j++) {
      if (board[i][j].first == c) {
        return {i, j};
      }
    }
  }

  return {-1, -1};
}

bool isVowel(pair<int, int> pos) {
  return board[pos.first][pos.second].second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  char l, r;
  cin >> l >> r;

  string str;
  cin >> str;

  int time = 0;
  for(char c : str) {
    pair<int, int> target = findPos(c);

    if (isVowel(target)) {
      pair<int, int> rPos = findPos(r);

      time += abs(rPos.first - target.first) + abs(rPos.second - target.second);

      r = c;
    }
    else {
      pair<int, int> lPos = findPos(l);

      time += abs(lPos.first - target.first) + abs(lPos.second - target.second);

      l = c;
    }

    time++;
  }

  cout << time << endl;

  return 0;
}

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

  // 스택의 바텀으로 갈수록 height(pair의 첫번째 원소)가 커진다.
  // 같은 height를 가진 원소가 여럿 있을 경우, pair의 두번째 원소의 값으로 그 개수를 나타낸다.
  stack<pair<int, int>> s;
  ll count = 0;
  for(int i = 0; i < n; i++) {
    int height;
    cin >> height;

    if (s.empty()) {
      s.push({height, 1});
      continue;
    }

    if (s.top().first > height) {
      // 스택 탑의 키가 현재 사람의 키보다 크다면, 현재 사람은 바로 앞 사람 밖에 보지 못한다. 즉 count++
      count++;
      s.push({height, 1});
    }
    else if (s.top().first == height) {
      // 스택 탑의 키가 현재 사람의 키와 같다면, 현재 사람은 같은 키를 가진 사람들 + 자기보다 키가 큰 한명을 볼 수 있다.
      int sameCount = s.top().second;
      s.pop();
      count += sameCount;

      // s의 구현상 바텀으로 갈수록 키가 커지니, 스택이 비어있지 않다면 항상 현재 사람보다 키가 큰 사람이다.
      if (not s.empty()) {
        count++;
      }

      s.push({height, sameCount + 1});
    }
    else {
      // 스택 탑의 키가 현재 사람의 키보다 작다면, 자기와 같은 키를 가진 사람이 나올 때까지 pop하면서 카운팅한다.
      while(not s.empty() and s.top().first < height) {
        count += s.top().second;
        s.pop();
      }

      // 이후 과정은 키가 같은 경우와 같다.
      int sameCount = 1;
      if (not s.empty() and s.top().first == height) {
        sameCount = s.top().second;
        s.pop();
        count += sameCount;

        sameCount++;
      }

      if (not s.empty()) {
        count++;
      }

      s.push({height, sameCount});
    }
  }

  cout << count << endl;

  return 0;
}

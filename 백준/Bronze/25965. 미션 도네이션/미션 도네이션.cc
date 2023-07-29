#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;

  while(T--) {
    int n;
    cin >> n;

    vector<tuple<ll, ll, ll>> missions;
    for(int i = 0; i < n; i++) {
      int k, d, a;
      cin >> k >> d >>a;

      missions.push_back({k, d, a});
    }

    int k, d, a;
    cin >> k >> d >> a;

    ll result = 0;
    for(int i = 0; i < n; i++) {
      ll mk, md, ma;
      tie(mk, md, ma) = missions[i];

      ll money = mk * k - md * d + ma * a;
      if (money >= 0) {
        result += money;
      }
    }

    cout << result << endl;
  }

  return 0;
}

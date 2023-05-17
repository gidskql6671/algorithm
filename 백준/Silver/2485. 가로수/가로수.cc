#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  vector<int> distances;
  for(int i = 1; i < n; i++) {
    distances.push_back(arr[i] - arr[i - 1]);
  }

  sort(distances.begin(), distances.end());

  int gcdVal = distances[0];
  for(int i = 1; i < distances.size(); i++) {
    gcdVal = gcd(distances[i], gcdVal);
  }

  int count = 0;
  for(int i = 0; i < distances.size(); i++) {
    count += distances[i] / gcdVal - 1;
  }

  cout << count << endl;

  return 0;
}
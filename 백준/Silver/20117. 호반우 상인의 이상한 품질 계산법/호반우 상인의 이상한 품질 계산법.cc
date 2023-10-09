#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int n;
int arr[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  int money = 0;
  int i = 0, j = n - 1;
  while(i < j) {
    money += arr[j] * 2;

    i++; j--;
  }

  if (i == j) {
    money += arr[i];
  }

  cout << money << endl;

  return 0;
}

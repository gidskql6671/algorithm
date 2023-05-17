#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  while(true) {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];

    if (arr[0] == 0) {
      break;
    }

    sort(arr, arr + 3);

    if (arr[0] + arr[1] > arr[2]) {
      if (arr[0] == arr[1] and arr[1] == arr[2]) {
        cout << "Equilateral\n";
      }
      else if (arr[0] == arr[1] or arr[1] == arr[2] or arr[0] == arr[2]) {
        cout << "Isosceles\n";
      }
      else {
        cout << "Scalene\n";
      }
    }
    else {
      cout << "Invalid\n";
    }

  }

  return 0;
}
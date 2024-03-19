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
    string input;
    cin >> input;

    int i = 0, j = input.size() - 1;
    int type = 0;
    while(i < j and type == 0) {
      if (input[i] == input[j]) {
        i++;
        j--;
      }
      else {
        type = 1;

        int i2 = i + 1, j2 = j;
        while(i2 < j2 and type == 1) {
          if (input[i2] == input[j2]) {
            i2++;
            j2--;
          }
          else {
            type = 2;
          }
        }

        if (type == 2) {
          i2 = i; j2 = j - 1;
          type = 1;
          while(i2 < j2 and type == 1) {
            if (input[i2] == input[j2]) {
              i2++;
              j2--;
            }
            else {
              type = 2;
            }
          }
        }
      }
    }

    cout << type << "\n";
  }

  return 0;
}

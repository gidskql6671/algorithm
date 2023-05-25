#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int n, m;
  cin >> n >> m;

  vector<string> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int count = 0;
  char letter[] = {'A', 'C', 'G', 'T'};
  string dna;
  for(int i = 0; i < arr[0].length(); i++) {
    dna += "T";
    int minVal = INF;
    for(int j = 0; j < 4; j++) {
      int val = 0;
      for(int k = 0; k < n; k++) {
        if (letter[j] != arr[k][i]) {
          val++;
        }
      }

      if (val < minVal) {
        dna[dna.length() - 1] = letter[j];
        minVal = val;
      }
    }
    count += minVal;
  }

  cout << dna << endl;
  cout << count << endl;

  return 0;
}

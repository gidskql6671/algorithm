#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int arr[14];

int bnp(int seedMoney) {
  int curMoney = seedMoney;
  int count = 0;

  for(int i = 0; i < 14; i++) {
    if (arr[i] <= curMoney) {
      count += curMoney / arr[i];
      curMoney %= arr[i];
    }
  }

  return curMoney + count * arr[13];
}

int timing(int seedMoney) {
  int curMoney = seedMoney;
  int count = 0;

  int consIncrease = 0, consDecrease = 0;
  for(int i = 1; i < 14; i++) {
    if (arr[i - 1] < arr[i]) {
      consIncrease++;
      consDecrease = 0;
    }
    else if (arr[i - 1] > arr[i]) {
      consDecrease++;
      consIncrease = 0;
    }
    else {
      consIncrease = 0;
      consDecrease = 0;
    }

    if (consIncrease >= 3) {
      curMoney += count * arr[i];
      count = 0;
    }
    else if (consDecrease >= 3) {
      count += curMoney / arr[i];
      curMoney %= arr[i];
    }
  }

  return curMoney + count * arr[13];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int seedMoney;
  cin >> seedMoney;

  for(int i = 0; i < 14; i++) {
    cin >> arr[i];
  }

  int bnpResult = bnp(seedMoney);
  int timingResult = timing(seedMoney);

  if (bnpResult == timingResult) {
    cout << "SAMESAME\n";
  }
  else if (bnpResult < timingResult) {
    cout << "TIMING\n";
  }
  else {
    cout << "BNP\n";
  }

  return 0;
}

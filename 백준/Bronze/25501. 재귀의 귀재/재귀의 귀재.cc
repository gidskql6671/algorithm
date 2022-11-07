// #include <bits/stdc++.h>
#include <iostream>
#define INF 987654321
typedef long long ll;

using namespace std;

int recurCount = 0;

int recursion(string &str, int l, int r){
  recurCount++;

  if(l >= r) return 1;
  else if(str[l] != str[r]) return 0;
  else return recursion(str, l + 1, r - 1);
}

int isPalindrome(string &str){
  return recursion(str, 0, str.size() - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int T;
  cin >> T;

  while(T--) {
    recurCount = 0;

    string input;
    cin >> input;

    cout << isPalindrome(input) << " ";
    cout << recurCount << "\n";
  }

  return 0;
}
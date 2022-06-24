#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(4);

  int total = 0;
  map<string, int> trees;
  while(true) {
    string name;
    getline(cin, name);
    if (cin.eof()) {
      break;
    }

    total++;

    auto item = trees.find(name);
    if (item == trees.end()) {
      trees.insert({name, 1});
    }
    else {
      trees[name] = item->second + 1;
    }
  }

  for (auto iter : trees) {
    string name = iter.first;
    int count = iter.second;
    double ratio = round((double) count / total * 100 * 1e4) * 1e-4;

    cout << name << " " <<  ratio << endl;
  }

  return 0;
}

#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;


int n, m;

int dfs(vector<vector<int>> &graph, int cur, int currentTime, vector<int> &finishTimes, vector<int> &visited, int identifier);
void calculateFinishTimes(vector<vector<int>> &graph, vector<int> &finishTimes);
void calculateSccs(vector<vector<int>> &reversedGraph, vector<int> &finishTimes, vector<int> &identifiers);
void solve(vector<vector<int>> &graph);

bool compare(vector<int> &a, vector<int> &b) {
  return a[0] < b[0];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> m;
  vector<vector<int>> graph(n + 1, vector<int>());
  for(int i = 0; i < m; i++) {
    int tail, head;
    cin >> tail >> head;

    graph[tail].push_back(head);
  }

  solve(graph);

  return 0;
}

int dfs(vector<vector<int>> &graph, int cur, int currentTime, vector<int> &finishTimes, vector<int> &visited, int identifier) {
  visited[cur] = identifier;

  currentTime++;
  for(int next : graph[cur]) {
    if (!visited[next]) {
      currentTime = dfs(graph, next, currentTime, finishTimes, visited, identifier);
      currentTime++;
    }
  }

  finishTimes[cur] = currentTime;

  return currentTime;
}

void calculateFinishTimes(vector<vector<int>> &graph, vector<int> &finishTimes) {
  vector<int> visited(graph.size(), 0);

  int currentTime = 1;
  for(int i = 1; i < graph.size(); i++) {
    if (!visited[i]) {
      currentTime = dfs(graph, i, currentTime, finishTimes, visited, 1);
    }
  }
}

void calculateSccs(vector<vector<int>> &reversedGraph, vector<int> &finishTimes, vector<int> &identifiers) {
  vector<pair<int, int>> finishTimeNodes;
  for(int i = 1; i < finishTimes.size(); i++) {
    finishTimeNodes.push_back({finishTimes[i], i});
  }
  sort(finishTimeNodes.begin(), finishTimeNodes.end(), greater<>());

  vector<int> tmp(reversedGraph.size(), 0);
  int identifier = 1;
  for(auto finishTimeNode : finishTimeNodes) {
    int node = finishTimeNode.second;

    if (!identifiers[node]) {
      dfs(reversedGraph, node, 1, tmp, identifiers, identifier++);
    }
  }
}

void solve(vector<vector<int>> &graph) {
  vector<int> finishTimes(graph.size(), 0);

  calculateFinishTimes(graph, finishTimes);

  vector<vector<int>> reversedGraph(graph.size(), vector<int>());
  for(int tail = 1; tail < graph.size(); tail++) {
    for(int head : graph[tail]) {
      reversedGraph[head].push_back(tail);
    }
  }

  vector<int> identifiers(reversedGraph.size(), 0);
  calculateSccs(reversedGraph, finishTimes, identifiers);

  vector<vector<int>> sccs;
  for(int i = 1; i < identifiers.size(); i++) {
    int identifier = identifiers[i];

    while(sccs.size() < identifier) {
      sccs.push_back(vector<int>());
    }

    sccs[identifier - 1].push_back(i);
  }

  sort(sccs.begin(), sccs.end(), compare);

  cout << sccs.size() << endl;
  for(auto scc : sccs) {
    for(int ele : scc) {
      cout << ele << " ";
    }
    cout << "-1\n";
  }
}
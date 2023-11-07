#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

bool isCyclicDFS(int node, unordered_map<int, bool> &visited,
                 unordered_map<int, bool> &dfsVisited,
                 unordered_map<int, list<int>> &adj) {

  visited[node] = true;
  dfsVisited[node] = true;

  for (auto neighbour : adj[node]) {
    if (!visited[neighbour]) {
      bool cycleDetected = isCyclicDFS(neighbour, visited, dfsVisited, adj);
      if (cycleDetected)
        return true;
    } else if (dfsVisited[neighbour]) {
      return true;
    }
  }

  dfsVisited[node] = false;
  return false;
}

int cycleDetectionDirGraph(int n, vector<pair<int, int>> &edges) {

  // create adjacncy list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  // call dfs for all components
  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      bool cycleFound = isCyclicDFS(i, visited, dfsVisited, adj);
      if (cycleFound)
        return true;
    }
  }
  return false;
}

int main() {
  vector<pair<int, int>> edges = {make_pair(1, 2), make_pair(2, 3),
                                  make_pair(1, 3)};
  int out = cycleDetectionDirGraph(3, edges);
  cout << out << endl;
  return 0;
}

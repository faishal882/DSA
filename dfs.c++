#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited,
         unordered_map<int, list<int>> &adj, vector<int> &component) {
  component.push_back(node);
  visited[node] = true;

  for (auto i : adj[node]) {
    if (!visited[i]) {
      dfs(i, visited, adj, component);
    }
  }
}

vector<vector<int>> DFS(int V, int E, vector<vector<int>> &edges) {
  // prepare adjList
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<int>> ans;
  unordered_map<int, bool> visited;

  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      vector<int> component;
      dfs(i, visited, adj, component);
      ans.push_back(component);
    }
  }

  return ans;
}

int main() {
  vector<vector<int>> edges = {{0, 2}, {0, 1}, {1, 2}, {3, 4}};
  vector<vector<int>> out = DFS(5, 4, edges);
  for (auto i : out) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}

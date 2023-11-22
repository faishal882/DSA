#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st,
         unordered_map<int, list<int>> &adj) {
  vis[node] = true;
  for (auto nbr : adj[node]) {
    if (!vis[nbr]) {
      dfs(nbr, vis, st, adj);
    }
  }
  st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis,
            unordered_map<int, list<int>> &adj) {
  vis[node] = true;
  for (auto nbr : adj[node]) {
    if (!vis[nbr]) {
      revDfs(nbr, vis, adj);
    }
  }
}

int stronglyConnectedComponent(int v, vector<vector<int>> edges) {
  // adj list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
  }

  // topo sort
  stack<int> st;
  unordered_map<int, bool> vis;
  for (int i = 0; i < v; i++) {
    if (!vis[i]) {
      dfs(i, vis, st, adj);
    }
  }

  // create a transpose graph
  unordered_map<int, list<int>> transpose;
  for (int i = 0; i < v; i++) {
    vis[i] = false;
    for (auto nbr : adj[i]) {
      transpose[nbr].push_back(i);
    }
  }

  // dfs call using transpose
  int count = 0;
  while (!st.empty()) {
    int top = st.top();
    st.pop();
    if (!vis[top]) {
      count++;
      revDfs(top, vis, transpose);
    }
  }

  return count;
}

int main() {
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 4}, {2, 3}, {3, 2}, {4, 0}};
  int out = stronglyConnectedComponent(5, edges);
  cout << out << endl;
  return 0;
}

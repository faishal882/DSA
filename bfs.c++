#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList,
                    vector<pair<int, int>> &edges) {
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
}

void bfs(unordered_map<int, list<int>> &adjList,
         unordered_map<int, bool> &visited, vector<int> ans, int node) {
  queue<int> q;
  q.push(node);
  visited[node] = 1;
  while (!q.empty()) {
    int frontNode = q.front();
    q.pop();

    ans.push_back(frontNode);

    for (auto i : adjList[frontNode]) {
      if (!visited[i]) {
        q.push(i);
        visited[i] = 1;
      }
    }
  }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
  unordered_map<int, list<int>> adjList;
  vector<int> ans;
  unordered_map<int, bool> visited;

  prepareAdjList(adjList, edges);

  // traverse all components of graph
  for (int i = 0; i < vertex; i++) {
    if (!visited[i]) {
      bfs(adjList, visited, ans, i);
    }
  }

  return ans;
}

int main() {
  vector<pair<int, int>> edges = {make_pair(0, 1), make_pair(0, 3),
                                  make_pair(1, 2), make_pair(2, 3)};
  vector<int> out = BFS(4, edges);
  for (auto i : out) {
    cout << i << " ";
  }
  return 0;
}

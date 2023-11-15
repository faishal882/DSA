#include <iostream>
#include <limits.h>
#include <list>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> dijkstraAlgo(vector<vector<int>> &vec, int vertices, int edges,
                         int source) {
  // create adj list
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < vertices; i++) {
    int u = vec[i][0];
    int v = vec[i][1];
    int w = vec[i][2];

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  vector<int> dist(vertices);
  for (int i = 0; i < vertices; i++)
    dist[i] = INT_MAX;

  set<pair<int, int>> st;
  dist[source] = 0;
  st.insert(make_pair(0, source));

  while (!st.empty()) {
    // fetch top record
    auto top = *(st.begin());
    int nodeDistance = top.first;
    int topNode = top.second;

    // remove top record
    st.erase(st.begin());

    // trvaerse on neighbours
    for (auto neighbour : adj[topNode]) {
      if (nodeDistance + neighbour.second < dist[neighbour.first]) {
        auto record =
            st.find(make_pair(dist[neighbour.first], neighbour.first));
        // if record found then erase it
        if (record != st.end()) {
          st.erase(record);
        }

        // distance update
        dist[neighbour.first] = nodeDistance + neighbour.second;
        // record push in set
        st.insert(make_pair(dist[neighbour.first], neighbour.first));
      }
    }
  }

  return dist;
}

int main() {
  vector<vector<int>> edges = {
      {0, 1, 5}, {0, 2, 8}, {1, 2, 9}, {1, 3, 2}, {2, 3, 6}};
  vector<int> out = dijkstraAlgo(edges, 4, 5, 0);
  for (auto i : out) {
    cout << i << " ";
  }
  cout << endl;
}

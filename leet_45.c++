#include "binary_tree.c++"
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

vector<int> verticalOrder(Node *root) {
  map<int, map<int, vector<int>>> nodes;
  queue<pair<Node *, pair<int, int>>> q;
  vector<int> ans;

  if (root == NULL) {
    return ans;
  }

  q.push(make_pair(root, make_pair(0, 0)));

  while (!q.empty()) {
    pair<Node *, pair<int, int>> tmp = q.front();
    q.pop();

    Node *frontNode = tmp.first;
    int hd = tmp.second.first;
    int lvl = tmp.second.second;

    nodes[hd][lvl].push_back(frontNode->data);

    if (frontNode->left)
      q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

    if (frontNode->right)
      q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
  }

  for (auto i : nodes) {
    for (auto j : i.second) {
      for (auto k : j.second) {
        ans.push_back(k);
      }
    }
  }

  return ans;
}

int main() {

  Node *root = NULL;
  root = buildTree(root);
  vector<int> output = verticalOrder(root);

  for (auto i : output) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}

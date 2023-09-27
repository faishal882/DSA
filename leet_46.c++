#include "binary_tree.c++"
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

vector<int> topView(Node *root) {
  vector<int> ans;

  if (root == NULL)
    return ans;

  map<int, int> topNode;
  queue<pair<Node *, int>> q;

  q.push(make_pair(root, 0));

  while (!q.empty()) {
    pair<Node *, int> tmp = q.front();
    q.pop();

    Node *frontNode = tmp.first;
    int hd = tmp.second;

    if (topNode.find(hd) == topNode.end())
      topNode[hd] = frontNode->data;

    if (frontNode->left)
      q.push(make_pair(frontNode->left, hd - 1));

    if (frontNode->right)
      q.push(make_pair(frontNode->right, hd + 1));
  }

  for (auto i : topNode) {
    ans.push_back(i.second);
  }

  return ans;
}

int main() {
  Node *root = NULL;
  root = buildTree(root);
  vector<int> output = topView(root);

  for (auto i : output) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}

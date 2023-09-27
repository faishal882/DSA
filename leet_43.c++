#include "binary_tree.c++"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> zigZagTravel(Node *node) {
  vector<int> ans;
  if (node == NULL) {
    return ans;
  }

  queue<Node *> q;
  q.push(node);

  bool leftToRight = true;

  while (!q.empty()) {
    int size = q.size();
    vector<int> result(size);

    // level process
    for (int i = 0; i < size; i++) {
      Node *frontNode = q.front();
      q.pop();

      int index = leftToRight ? i : size - i - 1;
      result[index] = frontNode->data;

      if (frontNode->left)
        q.push(frontNode->left);
      if (frontNode->right)
        q.push(frontNode->right);
    }

    // direction change
    leftToRight = !leftToRight;
    for (auto i : result) {
      ans.push_back(i);
    }
  }

  return ans;
}

int main() {
  Node *root = NULL;
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  root = buildTree(root);
  vector<int> ans = zigZagTravel(root);

  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}

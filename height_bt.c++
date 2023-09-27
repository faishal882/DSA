#include "binary_tree.c++"
#include <iostream>
using namespace std;

int height(Node *node) {
  if (node == NULL)
    return 0;

  int left = height(node->left);
  int right = height(node->right);

  int ans = max(left, right) + 1;

  return ans;
}

int main() {
  Node *root = NULL;

  root = buildTree(root);
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  int x = height(root);
  cout << "Height of tree: " << x << endl;
}

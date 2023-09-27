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

pair<int, int> fastDiameter(Node *root) {
  if (root == NULL) {
    pair<int, int> p = make_pair(0, 0);
    return p;
  }

  pair<int, int> left = fastDiameter(root->left);
  pair<int, int> right = fastDiameter(root->right);

  int op1 = left.first;
  int op2 = right.first;
  int op3 = left.second + right.second + 1;

  pair<int, int> ans;
  ans.first = max(op1, max(op2, op3));
  ans.second = max(left.second, right.second) + 1;

  return ans;
}

int diameter(Node *root) {
  if (root == NULL)
    return 0;

  int op1 = diameter(root->left);
  int op2 = diameter(root->right);
  int op3 = height(root->right) + height(root->left) + 1;

  int ans = max(op1, max(op2, op3));

  return ans;
}
int main() {
  Node *root = NULL;

  root = buildTree(root);
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  int x = diameter(root);
  int y = fastDiameter(root).first;
  cout << "Diameter of tree: " << x << " FAST: " << y << endl;

  return 0;
}

#include "binary_tree.c++"
#include <iostream>

int findPosition(int in[], int element, int n) {
  for (int i = 0; i < n; i++) {
    if (in[i] == element)
      return i;
  }

  return -1;
}

Node *solve(int in[], int pre[], int &preOrderIndex, int inOstartIndex,
            int inOendIndex, int n) {
  if (preOrderIndex >= n || inOstartIndex > inOendIndex)
    return NULL;

  int element = pre[preOrderIndex++];
  Node *root = new Node(element);
  int position = findPosition(in, element, n);

  root->left = solve(in, pre, preOrderIndex, inOstartIndex, position - 1, n);
  root->right = solve(in, pre, preOrderIndex, position + 1, inOendIndex, n);

  return root;
}
Node *buildTreeInOPreO(int in[], int pre[], int n) {
  int preOrderIndex = 0;
  Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
  return ans;
}

int main() {
  int inorder[6] = {3, 1, 4, 0, 5, 2};
  int preorder[6] = {0, 1, 3, 4, 2, 5};

  Node *ans = buildTreeInOPreO(inorder, preorder, 6);
  cout << ans->data << endl;
  postorder(ans);
}

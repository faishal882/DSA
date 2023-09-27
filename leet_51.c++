#include "bst.c++"
#include <iostream>
#include <vector>

void inorder_save(Node *root, vector<int> &in) {
  // base case
  if (root == NULL) {
    return;
  }

  inorder_save(root->left, in);
  in.push_back(root->data);
  inorder_save(root->right, in);
}

bool twoSumInBst(Node *root, int target) {
  vector<int> inorderVal;
  inorder_save(root, inorderVal);

  int i = 0, j = inorderVal.size() - 1;

  while (i < j) {
    int sum = inorderVal[i] + inorderVal[j];

    if (sum == target)
      return true;
    if (sum < target)
      i++;
    else
      j--;
  }

  return false;
}

int main() {
  Node *root = NULL;
  cout << "Enter data for bst: " << endl;
  takeInput(root);

  bool ans = twoSumInBst(root, 20);
  cout << ans << endl;
}

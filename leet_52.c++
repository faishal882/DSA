#include "bst.c++"
#include <iostream>
#include <vector>
using namespace std;

void inorder_save(Node *root, vector<int> &in) {
  // base case
  if (root == NULL) {
    return;
  }

  inorder_save(root->left, in);
  in.push_back(root->data);
  inorder_save(root->right, in);
}

Node *inorderToBst(int s, int e, vector<int> in) {
  // base case
  if (s > e)
    return NULL;

  int mid = (s + e) / 2;
  Node *root = new Node(in[mid]);
  root->left = inorderToBst(s, mid - 1, in);
  root->right = inorderToBst(mid + 1, e, in);

  return root;
}

Node *balancedBST(Node *root) {
  vector<int> in;
  inorder_save(root, in);
  Node *root_ans = inorderToBst(0, in.size() - 1, in);
  return root_ans;
}

int main() {
  Node *root = NULL;
  cout << "Enter data: ";
  takeInput(root);
  levelOrderTraversal(root);

  Node *output_root = balancedBST(root);
  levelOrderTraversal(output_root);
}

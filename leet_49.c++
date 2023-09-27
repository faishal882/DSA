#include "binary_tree.c++"
#include <iostream>
using namespace std;

Node *flattenTree(Node *root) {
  Node *curr = root;

  while (curr != NULL) {
    if (curr->left) {
      Node *pred = curr->left;
      while (pred->right) {
        pred = pred->right;
      }

      pred->right = curr->right;
      curr->right = curr->left;
      curr->left = NULL;
    }

    curr = curr->right;
  }

  return root;
}

int main() {
  Node *root = NULL;
  buildTree(root);
  Node *output = flattenTree(root);

  while (output->right) {
    cout << output->data << " ";
  }
  cout << endl;

  return 0;
}

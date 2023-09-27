#include "bst.c++"
#include <iostream>
using namespace std;

pair<int, int> predecessorSuccessor(Node *root, int key) {
  // find key
  Node *temp = root;
  int pred = -1;
  int succ = -1;

  while (temp->data != key) {
    if (temp->data > key) {
      succ = temp->data;
      temp = temp->left;
    } else {
      pred = temp->data;
      temp = temp->right;
    }
  }

  Node *leftTree = temp->left;
  while (leftTree != NULL) {
    pred = leftTree->data;
    leftTree = leftTree->right;
  }

  Node *rightTree = temp->right;
  while (rightTree != NULL) {
    succ = rightTree->data;
    rightTree = rightTree->left;
  }

  pair<int, int> ans = make_pair(pred, succ);
  return ans;
}

int main() {
  Node *root = NULL;

  cout << "Enter data to create bst" << endl;
  takeInput(root);

  pair<int, int> output = predecessorSuccessor(root, 5);
  cout << output.first << " " << output.second << endl;
}

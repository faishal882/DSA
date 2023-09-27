#include "bst.c++"
#include <iostream>
using namespace std;

class Info {
public:
  int maxi;
  int mini;
  bool isBst;
  int size;
};

Info solve(Node *root, int &ans) {
  if (root == NULL) {
    return {INT_MIN, INT_MAX, true, 0};
  }

  Info left = solve(root->left, ans);
  Info right = solve(root->right, ans);

  Info currNode;
  currNode.size = left.size + right.size + 1;
  currNode.maxi = max(root->data, right.maxi);
  currNode.mini = min(root->data, left.mini);

  if (left.isBst && right.isBst &&
      (root->data > left.maxi && root->data < right.mini)) {
    currNode.isBst = true;
  } else {
    currNode.isBst = false;
  }

  if (currNode.isBst) {
    ans = max(ans, currNode.size);
  }

  return currNode;
}

int largestBSTSubtree(Node *root) {
  int maxSize = 0;
  Info temp = solve(root, maxSize);
  return maxSize;
}

int main() {
  Node *root = NULL;
  cout << "Enter input for bst: ";
  takeInput(root);
  int output = largestBSTSubtree(root);
  cout << output << endl;
}

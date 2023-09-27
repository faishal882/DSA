#include <iostream>
#include <queue>
using namespace std;

class Node {

public:
  int data;
  Node *left;
  Node *right;

  Node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *insertIntoBST(Node *&root, int data) {
  if (root == NULL) {
    root = new Node(data);
    return root;
  }

  if (data > root->data)
    root->right = insertIntoBST(root->right, data);
  else
    root->left = insertIntoBST(root->left, data);

  return root;
}

void takeInput(Node *&root) {
  int data;
  cin >> data;

  while (data != -1) {
    root = insertIntoBST(root, data);
    cin >> data;
  }
}

void levelOrderTraversal(Node *root) {
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();

    if (temp == NULL) {
      cout << endl;
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
}

// LNR TRAVERSAL
void inorder(Node *root) {
  // base case
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

// NLR TRAVERSAL
void preorder(Node *root) {
  // base case
  if (root == NULL) {
    return;
  }

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

// LRN TRAVERSAL
void postorder(Node *root) {
  // base case
  if (root == NULL) {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

void morristraversal(Node *root) {}

Node *minValueNode(Node *root) {
  Node *mini = root;
  while (root->left) {
    mini = root->left;
  }

  return mini;
}

Node *deleteFromBST(Node *root, int val) {
  // base case
  if (root == NULL)
    return root;

  if (root->data == val) {
    // 0 child
    if (root->left == NULL && root->right == NULL) {
      delete root;
      return NULL;
    }

    // 1 child
    // left child
    if (root->left != NULL && root->right == NULL) {
      Node *tmp = root->left;
      delete root;
      return tmp;
    }

    // right child
    if (root->right != NULL && root->left == NULL) {
      Node *tmp = root->right;
      delete root;
      return tmp;
    }

    // 2 child
    if (root->left != NULL && root->right != NULL) {
      int mini = minValueNode(root->right)->data;
      root->data = mini;
      root->right = deleteFromBST(root->right, mini);
      return root;
    }

  } else if (root->data > val) {
    root->left = deleteFromBST(root->left, val);
    return root;
  } else {
    root->right = deleteFromBST(root->right, val);
    return root;
  }
}

// int main() {
//   Node *root = NULL;

//   cout << "Enter data to create BST: " << endl;
//   takeInput(root);

//   cout << "printing..." << endl;
//   levelOrderTraversal(root);

//   cout << "printing inorder..." << endl;
//   inorder(root);

//   cout << "min_value: " << minValueNode(root)->data << endl;

//   cout << "delete a node: " << endl;
//   Node *output = deleteFromBST(root, 30);
//   levelOrderTraversal(output);
//   return 0;
// }

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

Node *buildTree(Node *root) {
  cout << "Enter the data: " << endl;
  int data;
  cin >> data;
  root = new Node(data);

  if (data == -1) {
    return NULL;
  }

  cout << "Enter data for inserting in left: " << endl;
  root->left = buildTree(root->left);
  cout << "Enter data for inserting in right: " << endl;
  root->right = buildTree(root->right);
  return root;
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
/*
int main() {
  Node *root = NULL;

  root = buildTree(root);
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  cout << "PRinting tree data: " << endl;
  levelOrderTraversal(root);

  cout << "Inorder(LNR) Traversal is: " << endl;
  inorder(root);
  cout << endl << "Preorder(NLR) Traversal is: " << endl;
  preorder(root);
  cout << endl << "Postorder(LRN) Traversal is: " << endl;
  postorder(root);
  return 0;
} */

#include "bst.c++"
#include <iostream>
using namespace std;

void convertIntoDLL(Node *root, Node *&head) {
  if (root == NULL)
    return NULL;

  convertIntoDLL(root->right, head);

  root->right = head;
  if (head != NULL)
    head->left = root;

  head = root;

  convertIntoDLL(root->left, head);
}

Node *mergeLinkedList(Node *&head1, Node *&head2) {
  Node *head = NULL;
  Node *tail = NULL;

  while (head1 != NULL && head2 != NULL) {
    if (head1->data < head2->data) {
      if (head == NULL) {
        head = head1;
        tail = head1;
        head1 = head1->right;
      } else {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
      }
    } else {
      if (head == NULL) {
        head = head2;
        tail = head2;
        head2 = head2->right;
      } else {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
      }
    }
  }

  while (head1 != NULL) {
    tail->right = head1;
    head1->left = tail;
    tail = head1;
    head1 = head1->right;
  }

  while (head2 != NULL) {
    tail->right = head2;
    head2->left = tail;
    tail = head2;
    head1 = head2->right;
  }

  return head;
}

int countNodes(Node *head) {
  int cnt = 0;
  Node *temp = head;
  while (temp != NULL) {
    cnt++;
    temp = temp->right;
  }
  return cnt;
}

Node *dllToBst(Node *&head, int n) {

  // base case
  if (n <= 0 || head == NULL)
    return NULL;
  Node *left = dllToBst(head, n / 2);

  Node *root = head;
  root->left = left;

  head = head->right;

  root->right = dllToBst(head, n - n / 2 - 1);

  return root;
}

Node *mergeBST(Node *root1, Node *root2) {
  Node *head1 = NULL;
  convertIntoDLL(root1, head1);
  head1->left = NULL;

  Node *head2 = NULL;
  convertIntoDLL(root2, head2);
  head2->left = NULL;

  Node *head = mergeLinkedList(head1, head2);
  int n = countNodes(head);
  Node *root = dllToBst(head, n);
  return root;
}
int main() {
  Node *root1 = NULL;
  Node *root2 = NULL;

  cout << "Enter data for bst1: " << endl;
  takeInput(root1);
  levelOrderTraversal(root1);
  cout << "Enter data for bst2: " << endl;
  takeInput(root2);
  levelOrderTraversal(root2);

  Node *output_root = mergeBST(root1, root2);
  levelOrderTraversal(output_root);
}

#include "binary_tree.c++"
#include <iostream>
#include <map>
#include <queue>

Node *createParentMapping(Node *root, int target,
                          map<Node *, Node *> &nodeToParent) {
  Node *res = NULL;

  queue<Node *> q;
  q.push(root);
  nodeToParent[root] = NULL;

  while (!q.empty()) {
    Node *front = q.front();
    q.pop();

    if (front->data == target)
      res = front;
    if (front->left) {
      nodeToParent[front->left] = front;
      q.push(front->left);
    }

    if (front->right) {
      nodeToParent[front->right] = front;
      q.push(front->right);
    }
  }

  return res;
}

int burnTree(Node *root, map<Node *, Node *> &nodeToParent) {
  map<Node *, bool> visited;
  queue<Node *> q;

  int ans = 0;

  q.push(root);
  visited[root] = true;

  while (!q.empty()) {
    bool flag = 0;
    int size = q.size();
    for (int i = 0; i < size; i++) {
      Node *front = q.front();
      q.pop();

      if (front->left && !visited[front->left]) {
        flag = 1;
        q.push(front->left);
        visited[front->left] = 1;
      }

      if (front->right && !visited[front->right]) {
        flag = 1;
        q.push(front->right);
        visited[front->right] = 1;
      }

      if (nodeToParent[front] && !visited[nodeToParent[front]]) {
        flag = 1;
        q.push(nodeToParent[front]);
        visited[nodeToParent[front]] = 1;
      }
    }

    if (flag == 1) {
      ans++;
    }
  }

  return ans;
}

int minTime(Node *root, int target) {
  map<Node *, Node *> nodeToParent;
  cout << "working2..." << endl;
  Node *targetNode = createParentMapping(root, target, nodeToParent);
  cout << "working3..." << endl;
  int ans = burnTree(targetNode, nodeToParent);
  cout << "working4..." << endl;
  return ans;
}

int main() {
  Node *root = NULL;
  buildTree(root);
  cout << "WORKInG1.." << endl;
  int ans = minTime(root, 5);
  cout << ans << endl;
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node {
public:
  int data;
  int i;
  int j;

  node(int data, int row, int col) {
    this->data = data;
    i = row;
    j = col;
  }
};

class compare {
public:
  bool operator()(node *a, node *b) { return a->data > b->data; }
};

vector<int> mergeKSortedArray(vector<vector<int>> &kArrays, int k) {
  priority_queue<node *, vector<node *>, compare> minHeap;

  // step1: first elemnt of k arrays insert into minHeap;
  for (int i = 0; i < k; i++) {
    node *tmp = new node(kArrays[i][0], i, 0);
    minHeap.push(tmp);
  }

  vector<int> ans;
  // step2:
  while (minHeap.size() > 0) {
    node *tmp = minHeap.top();

    ans.push_back(tmp->data);
    minHeap.pop();

    int i = tmp->i;
    int j = tmp->j;

    if (j + 1 < kArrays[i].size()) {
      node *next = new node(kArrays[i][j + 1], i, j + 1);
      minHeap.push(next);
    }
  }

  return ans;
}

int main() {
  vector<vector<int>> arr = {{3, 5, 9}, {1, 2, 3, 8}};
  vector<int> ans = mergeKSortedArray(arr, 2);
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl;
}

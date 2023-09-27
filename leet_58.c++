#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

class node {
public:
  int data;
  int row;
  int col;

  node(int data, int r, int c) {
    this->data = data;
    row = r;
    col = c;
  }
};

class compare {
public:
  bool operator()(node *a, node *b) { return a->data > b->data; }
};

int KSortedArraySmallestRange(vector<vector<int>> &a, int k, int n) {
  priority_queue<node *, vector<node *>, compare> minHeap;
  int mini = INT_MAX, maxi = INT_MIN;

  for (int i = 0; i < k; i++) {
    int element = a[i][0];
    mini = min(mini, element);
    maxi = max(maxi, element);
    minHeap.push(new node(element, i, 0));
  }

  int start = mini, end = maxi;

  while (!minHeap.empty()) {
    node *tmp = minHeap.top();
    minHeap.pop();

    mini = tmp->data;

    if (maxi - mini < end - start) {
      start = mini;
      end = maxi;
    }

    if (tmp->col + 1 < n) {
      maxi = max(maxi, a[tmp->row][tmp->col + 1]);
      minHeap.push(new node(a[tmp->row][tmp->col + 1], tmp->row, tmp->col + 1));
    } else {
      break;
    }
  }

  return (end - start + 1);
}

int main() {
  vector<vector<int>> arr = {{2, 4, 5}, {5, 6, 7}, {2, 3},
                             {1, 1},    {9, 12},   {4, 9}};
  int ans = KSortedArraySmallestRange(arr, 6, 6);
  cout << ans << endl;
}

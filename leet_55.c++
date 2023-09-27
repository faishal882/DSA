#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int n, int k) {
  priority_queue<int> pq;

  for (int i = 0; i < k; i++) {
    pq.push(arr[i]);
  }

  for (int i = k; i < n; i++) {
    if (arr[i] < pq.top()) {
      pq.pop();
      pq.push(arr[i]);
    }
  }

  int ans = pq.top();
  return ans;
}

int main() {
  int arr[6] = {7, 10, 4, 3, 20, 15};
  int output = kthSmallest(arr, 6, 3);
  cout << output << endl;
}

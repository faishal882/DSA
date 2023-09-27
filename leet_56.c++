#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int getKthLargestSum(vector<int> &arr, int k) {

  priority_queue<int, vector<int>, greater<int>> min_heap;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[i];

      if (min_heap.size() < k) {
        min_heap.push(sum);
      } else {
        if (sum > min_heap.top()) {
          min_heap.pop();
          min_heap.push(sum);
        }
      }
    }
  }

  return min_heap.top();
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  int output = getKthLargestSum(arr, 3);
  cout << output << endl;

  return 0;
}

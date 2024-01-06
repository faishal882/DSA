#include <iostream>
#include <vector>
using namespace std;

int maxNonAdjacentSumArr(vector<int> &nums) {
  int n = nums.size();
  int prev2 = 0;
  int prev1 = nums[0];

  for (int i = 1; i < n; i++) {
    int incl = prev2 + nums[i];
    int excl = prev1 + 0;
    int ans = max(incl, excl);
    prev2 = prev1;
    prev1 = ans;
  }

  return prev1;
}

int main() {
  vector<int> nums = {2, 1, 9, 10};
  int out = maxNonAdjacentSumArr(nums);
  cout << out << endl;
  return 0;
}

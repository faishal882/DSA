#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int x) {
  vector<int> dp(x + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= x; i++) {
    for (int j = 0; j < nums.size(); j++) {
      if (i - nums[j] >= 0 && dp[i - nums[j]] != INT_MAX)
        dp[i] = min(dp[i], 1 + dp[i - nums[j]]);
    }
  }

  if (dp[x] == INT_MAX)
    return -1;
  return dp[x];
}

int minimumElements(vector<int> &num, int x) { return solve(num, x); }

int main() {
  vector<int> nums = {1, 2, 3};
  int out = minimumElements(nums, 7);
  cout << out << endl;
  return 0;
}

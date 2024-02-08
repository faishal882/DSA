#include <iostream>
#include <vector>
using namespace std;

int solve(int dice, int faces, int target) {
  vector<vector<int>> dp(dice + 1, vector<int>(target + 1, 0));
  // base case
  dp[0][0] = 1;

  for (int d = 1; d <= dice; d++) {
    for (int t = 1; t <= target; t++) {
      int ans = 0;
      for (int f = 1; f <= faces; f++) {
        if (t - f >= 0)
          ans = ans + dp[d - 1][t - f];
      }
      dp[d][t] = ans;
    }
  }

  return dp[dice][target];
}

int noOfWays(int M, int N, int X) { return solve(N, M, X); }

int main() {
  cout << noOfWays(6, 3, 12) << endl;
  return 0;
}

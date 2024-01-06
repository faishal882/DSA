#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &cost, int nStep, vector<int> &dp) {
  // base case
  if (nStep == 0)
    return cost[0];
  if (nStep == 1)
    return cost[1];
  if (dp[nStep] != -1)
    return dp[nStep];
  int ans =
      min(solve(cost, nStep - 1, dp), solve(cost, nStep - 2, dp)) + cost[nStep];
  dp[nStep] = ans;
  return ans;
}

// solving using tabulation method of dynamic programming
int solve2(vector<int> &cost, int n) {
  vector<int> dp(n + 1);
  dp[0] = cost[0];
  dp[1] = cost[1];

  for (int i = 2; i < n; i++)
    dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
  return min(dp[n - 1], dp[n - 2]);
}

int minCostClimbingStairs(vector<int> &cost) {
  // with dp
  int n = cost.size();
  // vector<int> dp(n + 1, -1);
  // return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
  return solve2(cost, n);
}

int main() {
  vector<int> cost = {10, 15, 20};
  int out = minCostClimbingStairs(cost);
  cout << out << endl;
  return 0;
}

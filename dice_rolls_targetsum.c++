#include <iostream>
#include <vector>
using namespace std;

int solve(int dice, int faces, int target, vector<vector<int>> &dp) {
  // base case
  if (target < 0)
    return 0;
  if (dice == 0 && target != 0)
    return 0;
  if (dice == 0 && target == 0)
    return 1;
  if (dp[dice][target] != -1)
    return dp[dice][target];

  int ans = 0;
  for (int i = 1; i <= faces; i++) {
    ans = ans + solve(dice - 1, faces, target - i, dp);
  }

  return dp[dice][target] = ans;
}

int noOfWays(int M, int N, int X) {
  vector<vector<int>> dp(N + 1, vector<int>(X + 1, -1));
  return solve(N, M, X, dp);
}

int main() {
  int out = noOfWays(6, 3, 12);
  cout << out << endl;
  return 0;
}

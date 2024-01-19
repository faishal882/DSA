#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int solve(vector<int> &obstacles, int currlane, int currpos,
          vector<vector<int>> &dp) {
  // base case
  int n = obstacles.size() - 1;
  if (currpos == n)
    return 0;

  if (dp[currlane][currpos] != -1)
    return dp[currlane][currpos];

  if (obstacles[currpos + 1] != currlane)
    return solve(obstacles, currlane, currpos + 1, dp);
  else {
    // sideways jump
    int ans = INT_MAX;
    for (int i = 1; i <= 3; i++) {
      if (currlane != i && obstacles[currpos] != i)
        ans = min(ans, 1 + solve(obstacles, i, currpos, dp));
    }
    dp[currlane][currpos] = ans;
    return dp[currlane][currpos];
  }
}

int minSideJumps(vector<int> &obstacles) {
  int n = obstacles.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return solve(obstacles, 2, 0, dp);
}

int main() {
  vector<int> obstacles = {0, 1, 2, 3, 0};
  int out = minSideJumps(obstacles);
  cout << out << endl;
  return 0;
}

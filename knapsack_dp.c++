#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int cpacity,
          vector<vector<int>> &dp) {
  // base case
  if (index == 0) {
    if (weight[0] <= cpacity)
      return value[0];
    else
      return 0;
  }

  if (dp[index][cpacity] != -1)
    return dp[index][cpacity];

  int include = 0;
  if (weight[index] <= cpacity)
    include = value[index] +
              solve(weight, value, index - 1, cpacity - weight[index], dp);
  int exclude = 0 + solve(weight, value, index - 1, cpacity, dp);

  dp[index][cpacity] = max(exclude, include);
  return dp[index][cpacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
  return solve(weight, value, n - 1, maxWeight, dp);
}

int main() {
  vector<int> weight = {1, 2, 4, 5};
  vector<int> value = {5, 4, 8, 6};
  int out = knapsack(weight, value, 4, 5);
  cout << out << endl;
  return 0;
}

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int solveMem(int n, int x, int y, int z, vector<int> &dp) {
  // base case
  if (n == 0)
    return 0;
  if (n < 0)
    return INT_MIN;
  if (dp[n] != -1)
    return dp[n];

  int a = solveMem(n - x, x, y, z, dp) + 1;
  int b = solveMem(n - y, x, y, z, dp) + 1;
  int c = solveMem(n - z, x, y, z, dp) + 1;

  dp[n] = max(a, max(b, c));
  return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
  vector<int> dp(n + 1, -1);
  return solveMem(n, x, y, z, dp);
}

int main() {
  int out = cutSegments(7, 5, 2, 2);
  cout << out << endl;
  return 0;
}

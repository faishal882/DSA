#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> &mat) {
  int row = mat.size();
  int col = mat[0].size();
  int maxi = 0;

  vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
  for (int i = row - 1; i >= 0; i--) {
    for (int j = col - 1; j >= 0; j--) {
      int right = dp[i][j + 1];
      int diagonal = dp[i + 1][j + 1];
      int down = dp[i + 1][j];

      if (dp[i][j] == 1) {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
      } else {
        dp[i][j] = 0;
      }
    }
  }

  return maxi;
}

int maxSquare(int n, int m, vector<vector<int>> mat) { return solve(mat); }

int main() {
  vector<vector<int>> mat = {{1, 1}, {1, 1}};
  int out = maxSquare(2, 2, mat);
  cout << out << endl;
  return 0;
}

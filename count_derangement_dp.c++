#include <iostream>
#include <vector>
using namespace std;

int solveTab(int n) {
  vector<int> dp(n + 1, 0);
  dp[1] = 0;
  dp[2] = 1;

  for (int i = 3; i <= n; i++) {
    int first = dp[i - 1];
    int second = dp[i - 2];
    int sum = (first + second);

    int ans = ((i - 1) * sum);
    dp[i] = ans;
  }

  return dp[n];
}

int countDerangements(int n) { return solveTab(n); }

int main() {
  int out = countDerangements(3);
  cout << out << endl;
  return 0;
}

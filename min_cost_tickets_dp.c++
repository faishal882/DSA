#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

// solution time-O(n), space-O(n);
int solve(int n, vector<int> &days, vector<int> &cost) {
  vector<int> dp(n + 1, INT_MAX);
  dp[n] = 0;

  for (int k = n - 1; k >= 0; k--) {
    // 1-day pass
    int option1 = cost[0] + dp[k + 1];

    int i;
    // 7-day pass
    for (i = k; i < n && days[i] < days[k] + 7; i++)
      ;
    int option2 = cost[1] + dp[i];

    // 30-day pass
    for (i = k; i < n && days[i] < days[k] + 30; i++)
      ;
    int option3 = cost[2] + dp[i];

    dp[k] = min(option1, min(option2, option3));
  }

  return dp[0];
}

// solution time-O(n), space-O(1);
int solve2(int n, vector<int> &days, vector<int> &cost) {
  int ans = 0;

  queue<pair<int, int>> month;
  queue<pair<int, int>> week;

  for (int day : days) {
    // step1: remove expired days
    while (!month.empty() && month.front().first + 30 <= day)
      month.pop();
    while (!week.empty() && week.front().first + 7 <= day)
      week.pop();

    // step2: add cost for current day
    week.push(make_pair(day, ans + cost[1]));
    month.push(make_pair(day, ans + cost[2]));

    // step3: ans update
    ans = min(ans + cost[0], min(week.front().second, month.front().second));
  }

  return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
  // return solve(n, days, cost);
  return solve2(n, days, cost);
}

int main() {
  vector<int> days = {1, 3, 4, 5, 7, 8, 10};
  vector<int> cost = {2, 7, 20};

  int out = minimumCoins(7, days, cost);
  cout << out << endl;

  return 0;
}

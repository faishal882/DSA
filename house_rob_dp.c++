#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &houses) {
  int n = houses.size();
  int prev2 = 0;
  int prev1 = houses[0];

  for (int i = 1; i < n; i++) {
    int incl = prev2 + houses[i];
    int excl = prev1 + 0;
    int ans = max(incl, excl);
    prev2 = prev1;
    prev1 = ans;
  }

  return prev1;
}

int houseRobbery(vector<int> &valueInHouses) {
  int n = valueInHouses.size();

  if (n == 1)
    return valueInHouses[0];

  vector<int> first, second;
  for (int i = 0; i < n; i++) {
    if (i != n - 1)
      first.push_back(valueInHouses[i]);
    if (i != 0)
      second.push_back(valueInHouses[i]);
  }

  return max(solve(first), solve(second));
}

int main() {
  vector<int> houses = {2, 1, 9, 10};
  int out = houseRobbery(houses);
  cout << out << endl;
  return 0;
}

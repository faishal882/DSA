#include <iostream>
using namespace std;

int numOfWaysToClimb(int n)
{
 if (n < 0)
  return 0;
 if (n == 0)
  return 1;
 int ans = numOfWaysToClimb(n - 1) + numOfWaysToClimb(n - 2);
 return ans;
}

int main()
{
 int n;
 cin >> n;
 int x = numOfWaysToClimb(n);
 cout << x << endl;

 return 0;
}
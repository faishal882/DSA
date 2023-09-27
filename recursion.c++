#include <iostream>
using namespace std;

int power(int n)
{
 if (n == 0)
  return 1;
 return 2 * power(n - 1);
}

void count(int n)
{
 if (n == 0)
 {
  return;
 }
 count(n - 1);
 cout << n << " ";
}

int fibonacci(int n)
{
 if (n == 0)
  return 0;
 if (n == 1)
  return 1;
 int ans = fibonacci(n - 1) + fibonacci(n - 2);
 return ans;
}

int main()
{
 int x;
 cin >> x;
 // int y = power(x);
 // cout << y << endl;
 // count(x);
 for (int i = 0; i < x; i++)
 {
  cout << fibonacci(i) << " ";
 }
 return 0;
}
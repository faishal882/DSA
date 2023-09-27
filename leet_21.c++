#include <iostream>
#include <vector>
using namespace std;

int modularExponentiation(int x, int n, int m)
{
 int res = 1;

 while (n > 0)
 {
  if (n & 1)
  {
   // odd
   res = (1LL * (res) * (x) % m) % m;
  }

  x = (1LL * (x) % m * (x) % m) % m;
  n = n >> 1; // same as n/2
 }

 return res;
}

int main()
{
 int x = 4, n = 3, m = 10;
 int y = modularExponentiation(x, n, m);
 cout << y << endl;

 return 0;
}
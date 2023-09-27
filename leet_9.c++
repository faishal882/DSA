#include <iostream>
using namespace std;

int Sqrt(int n)
{
 int s = 0;
 int e = n;
 int mid = s + (e - s) / 2;

 int ans = -1;
 while (s <= e)
 {
  int square = mid * mid;
  if (square == n)
  {
   return mid;
  }
  if(square < n) {
   ans = mid;
   s = mid+1;
  } else {
   e = mid - 1;
  }
  mid = s + (e - s) / 2;
 }

 return ans;
}

int main()
{
 int n = 36;
 int x= Sqrt(n);
 cout << "SQRT: " << x << endl;

 return 0;
}
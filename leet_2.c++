#include <iostream>
#include <math.h>
using namespace std;

class Solution {
 public:
  int reverse(int x) {
   int num = 0;
   while (x != 0)
   {
    int digit = x % 10;
    num = (num * 10) + digit;
    if((num > INT32_MAX / 10) || (num < INT32_MIN/10)) {
     return 0;
    }
    x = x / 10;
   }
   return num;
  }
};

int main()
{
 int n;
 cin >> n;

 Solution x;
 int y = x.reverse(n);
 cout <<y <<endl;
}
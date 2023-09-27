#include <iostream>
using namespace std;

void update(int n)
{
 n++;
}

void update2(int &n)
{
 n++;
}

// BAD PRACTICE
// int &func(int a)
// {
//  int num = a;
//  int &ans = num;
//  return ans;
// }

int main()
{
 /*
 int i = 5;

 // create a ref var
 int &j = i;
 cout << i << " " << j << endl;
 i++;
 cout << i << " " << j << endl;
 j++;
 cout << i << " " << j << endl;
 */
 int n = 5;
 cout << "Before: " << n << endl;
 update(n);
 cout << "After1: " << n << endl;
 update2(n);
 cout << "After2: " << n << endl;

 return 0;
}
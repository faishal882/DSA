#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &arr)
{
 // Write your code here
 int ans = 0;
 for (int i = 0; i < arr.size(); i++)
 {
  ans = ans ^ arr[i];
 }
 for (int i = 1; i < arr.size(); i++)
 {
  ans = ans ^ i;
 }
 return ans;
}

int main() {
 vector<int> arr = {4, 2, 1, 3, 1};
 int x = findDuplicate(arr);
 cout <<x <<endl;
 return 0;
}
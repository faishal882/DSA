#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

// AGGRESSIVE COWS

bool isPossible(vector<int> &stalls, int m, int mid)
{
 int cowCount = 1;
 int lastPos = stalls[0];

 for (int i = 0; i < stalls.size(); i++)
 {
  if (stalls[i] - lastPos >= mid)
  {
   cowCount++;
   if (cowCount == m)
   {
    return true;
   }
   lastPos = stalls[i];
  }
 }
 return false;
}

int cowKeep(vector<int> &stalls, int m)
{
 sort(stalls.begin(), stalls.end());
 int s = 0;
 int maxi = -1;
 for (int i = 0; i < stalls.size(); i++)
 {
  maxi = max(maxi, stalls[i]);
 }
 int e = maxi;
 int mid = s + (e - s) / 2;
 int ans = -1;

 while (s <= e)
 {
  if (isPossible(stalls, m, mid))
  {
   ans = mid;
   s = mid + 1;
  }
  else
  {
   e = mid - 1;
  }
  mid = s + (e - s) / 2;
 }
 return ans;
}

int main()
{
 vector<int> stalls = {4, 2, 1, 3, 6};
 int x = cowKeep(stalls, 2);
 cout << "MAX1: " << x << endl;

 return 0;
}
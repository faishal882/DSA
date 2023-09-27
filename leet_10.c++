#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid)
{
 int studentCount = 1;
 int pageSum = 0;

 for (int i = 0; i < n; i++)
 {
  if (pageSum + arr[i] <= mid)
  {
   pageSum += arr[i];
  }
  else
  {
   studentCount++;
   if (studentCount > m || arr[i] > mid)
   {
    return false;
   }
   pageSum = arr[i];
  }
 }
 return true;
}

int bookAllocation(int arr[], int n, int m)
{
 int min = 0;
 int max = 0;
 for (int i = 0; i < n; i++)
 {
  if (min < arr[i])
  {
   min = arr[i];
  }
  max = max + arr[i];
 }
 int mid = min + (max - min) / 2;
 int ans = -1;
 while (min <= max)
 {
  if (isPossible(arr, n, m, mid))
  {
   ans = mid;
   max = mid - 1;
  }
  else
  {
   min = mid + 1;
  }
  mid = min + (max - min) / 2;
 }

 return ans;
}

int main()
{
 int arr[4] = {12, 34, 67, 90};
 int arr2[4] = {5, 17, 100, 11};
 int x = bookAllocation(arr, 4, 2);
 int y = bookAllocation(arr2, 4, 4);
 cout <<"MAX1: " <<x <<" MAX2: " <<y <<endl;

 return 0;
}
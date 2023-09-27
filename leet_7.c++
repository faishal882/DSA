#include <iostream>
using namespace std;

int firstOccur(int arr[], int n, int k)
{
 int ans = -1;
 int start = 0;
 int end = n - 1;

 int mid = start + (end - start) / 2;
 while (start <= end)
 {
  if (arr[mid] == k)
  {
   ans = mid;
   end = mid - 1;
  }
  else if (k > arr[mid])
  {
   start = mid + 1;
  }
  else
  {
   end = mid - 1;
  }

  mid = start + (end - start) / 2;
 }
 return ans;
}

int lastOccur(int arr[], int n, int k)
{
 int ans = -1;
 int start = 0;
 int end = n - 1;

 int mid = start + (end - start) / 2;
 while (start <= end)
 {
  if (arr[mid] == k)
  {
   ans = mid;
   start = mid + 1;
  } 
  else if (k > arr[mid])
  {
   start = mid + 1;
  }
  else
  {
   end = mid - 1;
  }

  mid = start + (end - start) / 2;
 }
 return ans;
}

int main()
{
 int arr[8] = {1, 2, 3, 3, 3, 3, 3, 5};
 int x = firstOccur(arr, 8, 3);
 int y = lastOccur(arr, 8, 3);
 cout <<"FIRST: " <<x <<" LAST: " <<y <<endl;
 return 0;
}
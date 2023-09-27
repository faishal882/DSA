#include <iostream>
using namespace std;

bool binarySearchRec(int *arr, int s, int e, int k)
{
 if (s > e)
  return false;

 int mid = s + (e - s) / 2;
 if (arr[mid] == k)
  return true;
 if (arr[mid] < k)
  return binarySearchRec(arr, mid + 1, e, k);
 else
  return binarySearchRec(arr, s, mid - 1, k);
}

int binarySearch(int arr[], int size, int key)
{
 int start = 0;
 int end = size - 1;

 int mid = start + (end - start) / 2;
 while (start <= end)
 {
  if (arr[mid] == key)
  {
   return mid;
  }
  if (key > arr[mid])
  {
   start = mid + 1;
  }
  else
  {
   end = mid - 1;
  }

  mid = (start + end) / 2;
 }
 return -1;
}

int main()
{
 int even[6] = {1, 2, 4, 6, 8, 10};
 int odd[7] = {1, 2, 3, 4, 5, 6, 7};
 int index = binarySearch(even, 6, 8);
 int odd_index = binarySearch(odd, 7, 5);
 bool x = binarySearchRec(even, 0, 6, 8);
 bool y = binarySearchRec(odd, 0, 7, 11);
 cout << index << " " << odd_index << endl;
 cout << x << " " << y << endl;
 return 0;
}

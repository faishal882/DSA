#include <iostream>
#include <math.h>
using namespace std;

int findUnique(int *arr, int size)
{
 int ans = 0;
 for (int i = 0; i < size; i++)
 {
  ans = ans ^ arr[i];
 }
 return ans;
}

void printArray(int arr[], int size)
{
 for (int i = 0; i < size; i++)
 {
  cout << arr[i] << " ";
 }
 cout << endl;
}

int swapAlternate(int arr[], int size)
{
 for (int i = 0; i < size; i += 2)
 {
  if (i + 1 < size)
  {
   swap(arr[i], arr[i + 1]);
  }
 }
}

int main()
{
 int even[8] = {5, 2, 9, 4, 6, 7, 8, 1};
 int odd[7] = {5, 2, 9, 4, 6, 7, 8};
 int uniq[7] = {4, 3, 2, 4, 3, 2, 9};
 swapAlternate(even, 8);
 printArray(even, 8);
 swapAlternate(odd, 7);
 printArray(odd, 7);
 int x = findUnique(uniq, 7);
 cout <<x <<endl;
 return 0;
}
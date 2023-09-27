#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n)
{
 for (int i = 0; i < n; i++)
 {
  cout << arr[i] << " ";
 }
 cout << endl;
}

void mergeSorted(int arr1[], int arr2[], int arr_merge[], int n, int m)
{
 int i = 0;
 int j = 0;
 int k = 0;
 while (i < n && j < m)
 {
  if (arr1[i] < arr2[j])
  {
   arr_merge[k] = arr1[i];
   k++;
   i++;
  }
  else
  {
   arr_merge[k] = arr2[j];
   k++;
   j++;
  }
 }
 while (i < n)
 {
  arr_merge[k++] = arr1[i++];
 }
 while (j < m)
 {
  arr_merge[k++] = arr2[j++];
 }
}

int main()
{
 int arr1[5] = {1, 3, 5, 7, 9};
 int arr2[3] = {2, 4, 6};
 int arr_merge[8];
 mergeSorted(arr1, arr2, arr_merge, 5, 3);
 printArray(arr_merge, 8);
 return 0;
}
#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
 for (int i = 0; i < n; i++)
 {
  cout << arr[i] << " ";
 }
 cout << endl;
}

void insertionSort(int arr[], int n)
{
 for (int i = 1; i < n; i++)
 {
  int temp = arr[i];
  int j = i-1;
  for (; j >= 0; j--)
  {
   if (arr[j] > temp)
   {
    arr[j + 1] = arr[j];
   }
   else
   {
    break;
   }
  }
  arr[j + 1] = temp;
 }
}

int main()
{
 int arr[8] = {29, 72, 13, 87, 56, 52, 51, 35};
 insertionSort(arr, 8);
 printArray(arr, 8);
 return 0;
}
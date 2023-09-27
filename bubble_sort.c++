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

void bubbleSort(int arr[], int n)
{
 for (int i = 0; i < n; i++)
 {
  bool swapped = false;
  for (int j = 0; j < n - i; j++)
  {
   if (arr[j] > arr[j + 1])
   {
    swap(arr[j], arr[j + 1]);
    swapped = true;
   }
  }
  if (swapped == false)
  {
   break;
  }
 }
}

int main()
{
 int arr[8] = {29, 72, 13, 87, 56, 52, 51, 35};
 bubbleSort(arr, 8);
 printArray(arr, 8);
 return 0;
}
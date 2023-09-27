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
void SelectionSort(int arr[], int n)
{
 for (int i = 0; i < n - 1; i++)
 {
  int minIndex = i;
  for (int j = i + 1; j < n; j++)
  {
   if (arr[j] < arr[minIndex])
   {
    minIndex = j;
   }
  }
  swap(arr[i], arr[minIndex]);
 }
}

int main()
{
 int arr[8] = {29, 72, 13, 87, 56, 52, 51, 35};
 SelectionSort(arr, 8);
 printArray(arr, 8);
 return 0;
}
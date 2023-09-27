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

void moveZeros(int arr[], int n)
{
 int i = 0;
 for (int j = 0; j < n; j++)
 {
  if (arr[j] != 0)
  {
   swap(arr[j], arr[i]);
   i++;
  }
 }
}

int main()
{
 int arr[8] = {1, 3, 0, 5, 7, 0, 9, 0};
 moveZeros(arr, 8);
 printArray(arr, 8);
 return 0;
}
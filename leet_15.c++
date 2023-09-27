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

bool checkRotatedSorted(int arr[], int m)
{
 int count = 0;
 int n = m;
 for (int i = 1; i < n; i++)
 {
  if (arr[i - 1] > arr[i])
  {
   count++;
  }
 }
 if (arr[n - 1] > arr[0])
 {
  count++;
 }
 return count <= 1;
}

int main()
{
 int arr[6] = {3, 4, 5, 6, 1, 2};
 bool x = checkRotatedSorted(arr, 6);
 cout << x << " " << endl;
 return 0;
}
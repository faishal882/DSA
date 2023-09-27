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

void rotateArray(int arr[], int n, int k)
{
 int temp[n];
 for(int i=0; i<n; i++) {
  temp[(i+k)%n] = arr[i];
 }
 printArray(temp, n);
}

int main()
{
 int arr[7] = {1, 2, 3, 4, 5, 6, 7};
 rotateArray(arr, 7, 3);
 return 0;
}
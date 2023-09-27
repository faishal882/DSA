#include <iostream>
using namespace std;

bool searchMatrix(int arr[][3], int m, int n, int tartget)
{
 int row = m, col = n;
 int start = 0, end = col * row - 1;

 int mid = start + (end - start) / 2;
 while (start <= end)
 {
  int element = arr[mid / col][mid % col];

  if (element == tartget)
  {
   return 1;
  }
  if (element < tartget)
  {
   start = mid + 1;
  }
  else
  {
   end = mid - 1;
  }
  mid = start + (end - start) / 2;
 }
 return 0;
}

int main()
{
 int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
 int target;
 cin >> target;
 bool x = searchMatrix(arr, 3, 3, target);
 cout << x << endl;
 return 0;
}
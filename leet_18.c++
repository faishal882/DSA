#include <iostream>
using namespace std;

void spiralPrint(int arr[][3], int m, int n)
{
 int row = m, col = n;
 int count = 0;
 int total = row * col;

 int start_col = 0, end_col = n - 1;
 int start_row = 0, end_row = m - 1;
 while (count < total)
 {
  // print starting row
  for (int index = start_col; count < total && index <= end_col; index++)
  {
   cout << arr[start_row][index] << " ";
   count++;
  }
  start_row++;

  // print ending col
  for (int index = start_row; count < total && index <= end_row; index++)
  {
   cout << arr[index][end_col] << " ";
   count++;
  }
  end_col--;

  // print ending row
  for (int index = end_col; count < total && index >= start_col; index--)
  {
   cout << arr[end_row][index] << " ";
   count++;
  }
  end_row--;

  // print starting col
  for (int index = end_row; count < total && index >= start_row; index--)
  {
   cout << arr[index][start_col] << " ";
   count++;
  }
  start_col++;
 }
}

int main()
{
 int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
 spiralPrint(arr, 3, 3);
 return 0;
}

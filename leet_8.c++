#include <iostream>
using namespace std;

int mountainPeakIndex(int arr[], int n)
{
 int s = 0, e = n - 1;
 int mid = s + (e - s) / 2;

 while (s < e)
 {
  if (arr[mid] < arr[mid + 1])
  {
   s = mid + 1;
  }
  else
  {
   e = mid;
  }
  mid = s + (e - s) / 2;
 }
 return s;
}

int main()
{
 int arr[7] = {3, 4, 5, 6, 2, 1, 0};
 int x = mountainPeakIndex(arr, 7);
 cout << "PEAK: " << x << endl;

 return 0;
}
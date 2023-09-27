#include <iostream>
using namespace std;

bool linearSearch(int *arr, int size, int k)
{
 if (size == 0)
  return false;
 if (arr[0] == k)
  return true;
 else
 {
  bool remainingPart = linearSearch(arr + 1, size - 1, k);
  return remainingPart;
 }
}

int main()
{
 int even[6] = {1, 2, 4, 6, 8, 10};
 bool index = linearSearch(even, 6, 9);
 cout << index << endl;

 return 0;
}
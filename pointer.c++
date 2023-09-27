#include <iostream>
using namespace std;

void update(int *p)
{
 // p = p + 5;
 // cout <<" Inside " <<p <<endl;
 *p = *p + 5;
}

int main()
{

 // int arr[10] = {2, 5, 6};
 // cout << " address of first memory block is " << arr << endl;
 // cout << " address of first memory block is " << &arr[0] << endl;
 // cout << " 4th " << *arr << endl;
 // cout << " 5th " << *arr + 1 << endl;
 // cout << " 6th " << *(arr + 1) << endl;
 // cout << " 7th " << 2 [arr] << endl; // i[arr] = arr[i] = *(arr + i) = *(i + arr)
 // cout << sizeof(arr) << endl;
 // cout << sizeof(int) << " " << sizeof(double) << endl;

 // double temp[10];
 // double *ptr = &temp[0];
 // cout << sizeof(temp) << endl;
 // cout << sizeof(ptr) << endl;
 // cout << sizeof(&ptr) << endl;
 // cout << sizeof(*ptr) << endl;
 // cout << ptr << endl;
 // cout << &ptr << endl;

 // int arr[5] = {1, 2, 3, 4, 5};
 // char ch[6] = "abcde";

 // char *c = &ch[0];
 // cout << arr << endl;
 // cout << ch << endl;
 // cout << c << endl;

 // char t = 'z';
 // char *p = &t;
 // cout << p << endl;
 int value = 5;
 int *p = &value;

 cout << " Before " << p << endl;
 cout << " Before " << *p << endl;
 update(p);
 cout << " After " << p << endl;
 cout << " After " << *p << endl;

 return 0;
}
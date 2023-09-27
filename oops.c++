#include <iostream>
using namespace std;

class Human
{
public:
 int height;
 int weight;
 int age;

public:
 int getAge()
 {
  return this->age;
 }
 int setWeight(int w)
 {
  this->weight = w;
 }

 // operator overload
 void operator+(Human &obj)
 {
  cout << "OPERATOR OVERLOADED" << endl;
 }

 void operator()()
 {
  cout << "OPERATOR OVERLOADED BRACKET" << endl;
 }
};

class Male : public Human
{
public:
 string color;

 void sleep()
 {
  cout << "Sleeping" << endl;
 }
};

int main()
{
 Male objct1;
 Human obj1;
 Human obj2;
 obj1.age = 4;
 obj2.age = 6;
 obj1 + obj2;
 obj1();
}

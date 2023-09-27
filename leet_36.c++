#include "stack.c++"
#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &input, int count, int size) {
  if (count == size / 2) {
    int x = input.top();
    cout << x << endl;
    input.pop();
    return;
  }

  int num = input.top();
  input.pop();

  solve(input, count + 1, size);

  input.push(num);
}

int main(int argc, char *argv[]) {
  stack<int> s;
  s.push(1);
  s.push(3);
  s.push(4);
  s.push(5);

  solve(s, 2, 4);
  return 0;
}

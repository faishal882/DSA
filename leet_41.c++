#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool knows(vector<vector<int>> &m, int a, int b) {
  if (m[a][b] == 1)
    return true;
  else
    return false;
}
int celebrity(vector<vector<int>> &m, int n) {

  stack<int> s;
  for (int i = 0; i < n; i++) {
    s.push(i);
  }

  while (s.size() > 1) {
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();

    if (knows(m, a, b))
      s.push(b);
    else
      s.push(a);
  }

  int candidate = s.top();
  bool rowCheck = false;
  int zeroCount = 0;

  for (int i = 0; i < n; i++) {
    if (m[candidate][i] == 0) {
      zeroCount++;
    }
  }

  if (zeroCount == n) {
    rowCheck = true;
  }

  bool colCheck = false;
  int colCount = 0;

  for (int i = 0; i < n; i++) {
    if (m[i][candidate] == 1) {
      colCount++;
    }
  }

  if (colCount == n - 1) {
    colCheck = true;
  }

  if (rowCheck == true && colCheck == true)
    return candidate;
  else
    return -1;
}

int main() {
  vector<vector<int>> m = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
  int x = celebrity(m, 3);
  cout << x << endl;
  return 0;
}

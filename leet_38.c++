#include <iostream>
#include <stack>
using namespace std;

bool redundantBrackets(string exp) {
  stack<char> s;

  for (int i = 0; i < exp.length(); i++) {
    char ch = exp[i];

    if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      s.push(ch);
    }
    if (!s.empty()) {
      char top = s.top();
      if ((ch == ')' &&
           (top == '+' || top == '-' || top == '*' || top == '/'))) {
        while (s.top() != '(') {
          s.pop();
        }
        s.pop();
      }
    }
  }

  if (s.empty())
    return true;
  else
    return false;
}

int main() {
  string s = "(a+b)";
  string s1 = "(a+c*b)+(c))";
  string s2 = "((a+b)*c)";
  bool x = redundantBrackets(s);
  bool y = redundantBrackets(s1);
  bool z = redundantBrackets(s2);
  cout << x << " " << y << " " << z << endl;
  return 0;
}

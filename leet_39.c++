#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str) {
  int nops = 0;

  stack<char> s;

  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];

    if (ch == '{')
      s.push(ch);
    else {
      if (s.empty()) {
        ch = '}';
        s.push(ch);
        nops++;
      } else {
        s.pop();
      }
    }
  }

  int size = s.size();
  if (size % 2 == 0) {
    int x = size / 2;
    nops = nops + x;
    return nops;
  } else {
    return -1;
  }
}

int main() {
  string s = "{{{}";
  string s1 = "{{}{}}";
  int x = findMinimumCost(s);
  int y = findMinimumCost(s1);
  cout << x << " " << y << endl;
  ;
  return 0;
}

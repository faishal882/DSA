// SUBSTRING
#include <iostream>
#include <vector>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans)
{

 // base case
 if (index >= str.length())
 {
  if (output.length() > 0)
   ans.push_back(output);
  return;
 }

 // exclude
 solve(str, output, index + 1, ans);

 // include
 int element = str[index];
 output.push_back(element);
 solve(str, output, index + 1, ans);
}

vector<string> substrings(string str)
{
 vector<string> ans;
 string output = "";
 int index = 0;
 solve(str, output, index, ans);
 return ans;
}

int main()
{
 string s = "abc";
 vector<string> output = substrings(s);

 for (int i = 0; i < output.size(); i++)
 {
  cout << output[i] << " ";
 }
 cout << endl;
 return 0;
}
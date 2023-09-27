// SUBSET(POWER SET)
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{

 // base case
 if (index >= nums.size())
 {
  ans.push_back(output);
  return;
 }

 // exclude
 solve(nums, output, index + 1, ans);

 // include
 int element = nums[index];
 output.push_back(element);
 solve(nums, output, index + 1, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
 vector<vector<int>> ans;
 vector<int> output;
 int index = 0;
 solve(nums, output, index, ans);
 return ans;
}

int main()
{
 vector<int> arr = {1, 2, 3};

 vector<vector<int>> output = subsets(arr);

 for (int i = 0; i < output.size(); i++)
 {
  cout << "[";
  for (int j = 0; j < output[i].size(); j++)
  {
   cout << output[i][j] <<" ";
  }
  cout << "] ";
 }
 cout << endl;
 return 0;
}
// RATMAZE PROBLEM
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> maze)
{
 if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0 && maze[x][y] == 1))
 {
  true;
 }
 else
  return false;
}

void solve(vector<vector<int>> &maze, int n, vector<string> &ans, vector<vector<int>> visited, int x, int y, string path)
{
 // base case
 if (x == n - 1 && y == n - 1)
 {
  ans.push_back(path);
  return;
 }

 visited[x][y] = 1;

 // 4-choices: U, D, L, R
 // DOWN
 int newx = x + 1, newy = y;
 if (isSafe(newx, newy, n, visited, maze))
 {
  path.push_back('D');
  solve(maze, n, ans, visited, newx, newy, path);
  path.pop_back();
 }

 // UP
 newx = x - 1, newy = y;
 if (isSafe(newx, newy, n, visited, maze))
 {
  path.push_back('U');
  solve(maze, n, ans, visited, newx, newy, path);
  path.pop_back();
 }

 // LEFT
 newx = x, newy = y - 1;
 if (isSafe(newx, newy, n, visited, maze))
 {
  path.push_back('L');
  solve(maze, n, ans, visited, newx, newy, path);
  path.pop_back();
 }

 // RIGHT
 newx = x, newy = y + 1;
 if (isSafe(newx, newy, n, visited, maze))
 {
  path.push_back('R');
  solve(maze, n, ans, visited, newx, newy, path);
  path.pop_back();
 }

 visited[x][y] == 0;
}

vector<string> ratMaze(vector<vector<int>> maze, int n)
{
 vector<string> ans;
 if (maze[0][0] == 0)
 {
  return ans;
 }
 int srcx = 0, srcy = 0;

 vector<vector<int>> visited = maze;
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < n; j++)
  {
   visited[i][j] = 0;
  }
 }

 string path = "";
 solve(maze, n, ans, visited, srcx, srcy, path);
 sort(ans.begin(), ans.end());
 return ans;
}

int main()
{
 vector<vector<int>> maze = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1, 1}};

 vector<string> output = ratMaze(maze, 4);

 for (auto i : output)
 {
  cout << i << " ";
 }
 cout << endl;

 return 0;
}
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<int>> &arr,
            vector<vector<bool>> &vis, int n) {
  if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) &&
      vis[newx][newy] != 1 && arr[newx][newy] == 1) {
    return true;
  } else {
    return false;
  }
}
void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans,
           vector<vector<bool>> &vis, string path) {
  // base case
  if (x == n - 1 && y == n - 1) {
    ans.push_back(path);
    return;
  }

  // 4movement: D, L, R, U
  vis[x][y] = 1;
  // DOWN
  if (isSafe(x + 1, y, arr, vis, n)) {
    solve(x + 1, y, arr, n, ans, vis, path + 'D');
  }

  // LEFT
  if (isSafe(x, y - 1, arr, vis, n)) {
    solve(x, y - 1, arr, n, ans, vis, path + 'L');
  }

  // RIGHT
  if (isSafe(x, y + 1, arr, vis, n)) {
    solve(x, y + 1, arr, n, ans, vis, path + 'R');
  }

  // UP
  if (isSafe(x - 1, y, arr, vis, n)) {
    solve(x - 1, y, arr, n, ans, vis, path + 'U');
  }
  vis[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
  vector<string> ans;
  vector<vector<bool>> visited(n, vector<bool>(n, 0));
  string path = "";
  if (arr[0][0] == 0)
    return ans;

  solve(0, 0, arr, n, ans, visited, path);
  return ans;
}

int main() {
  vector<vector<int>> arr = {
      {1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
  vector<string> out = searchMaze(arr, 4);
  for (auto i : out) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}

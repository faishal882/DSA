#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
  int x = row;
  int y = col;

  // check for same row
  while (y >= 0) {
    if (board[x][y] == 1)
      return false;
    y--;
  }

  x = row;
  y = col;
  while (x >= 0 && y >= 0) {
    if (board[x][y] == 1)
      return false;
    x--;
    y--;
  }

  x = row;
  y = col;
  while (x < n && y >= 0) {
    if (board[x][y] == 1)
      return false;
    x++;
    y--;
  }

  return true;
}

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
  vector<int> temp;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp.push_back(board[i][j]);
    }
  }

  ans.push_back(temp);
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board,
           int n) {
  // base case
  if (col == n) {
    addSolution(ans, board, n);
    return;
  }

  for (int row = 0; row < n; row++) {
    if (isSafe(row, col, board, n)) {
      // if placing queen safe
      board[row][col] = 1;
      solve(col + 1, ans, board, n);
      // backtrack
      board[row][col] = 0;
    }
  }
}

vector<vector<int>> solveNQueens(int n) {
  vector<vector<int>> ans;
  vector<vector<int>> board(n, vector<int>(n, 0));
  solve(0, ans, board, n);
  return ans;
}
int main() {
  int in = 4;
  vector<vector<int>> out = solveNQueens(4);

  for (auto i : out) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val) {
  int n = board[0].size();
  for (int i = 0; i < n; i++) {
    // row check
    if (board[row][i] == val)
      return false;
    // col check
    if (board[i][col] == val)
      return false;
    // 3*3 matrix check
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
      return false;
  }

  return true;
}

bool solve(vector<vector<int>> &board) {
  int n = board[0].size();

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      // cell empty
      if (board[row][col] == 0) {
        for (int val = 1; val <= 9; val++) {
          if (isSafe(row, col, board, val)) {
            board[row][col] = val;
            // recursive call
            bool aageSolPossibe = solve(board);
            if (aageSolPossibe)
              return true;
            else {
              // backtrack
              board[row][col] = 0;
            }
          }
        }
        return false;
      }
    }
  }

  return true;
};

void solveSudoku(vector<vector<int>> &sudoku) { solve(sudoku); }

int main() {
  vector<vector<int>> sudoku(9, vector<int>(9, 0));
  solveSudoku(sudoku);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << sudoku[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

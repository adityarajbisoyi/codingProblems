bool isSafe1(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      solve(0, board, ans, n);
      return ans;
    }


class Solution:
    def isSafe1(self, row, col, board, n):
        # Check upper diagonal on the left side
        duprow = row
        dupcol = col

        while row >= 0 and col >= 0:
            if board[row][col] == 'Q':
                return False
            row -= 1
            col -= 1

        col = dupcol
        row = duprow
        # Check left side in the same row
        while col >= 0:
            if board[row][col] == 'Q':
                return False
            col -= 1

        row = duprow
        col = dupcol
        # Check lower diagonal on the left side
        while row < n and col >= 0:
            if board[row][col] == 'Q':
                return False
            row += 1
            col -= 1

        return True

    def solve(self, col, board, ans, n):
        # Base case: If all queens are placed
        if col == n:
            ans.append(["".join(row) for row in board])
            return

        for row in range(n):
            if self.isSafe1(row, col, board, n):
                board[row][col] = 'Q'
                self.solve(col + 1, board, ans, n)
                board[row][col] = '.'  # Backtrack

    def solveNQueens(self, n):
        ans = []
        board = [["." for _ in range(n)] for _ in range(n)]  # Initialize the board
        self.solve(0, board, ans, n)
        return ans
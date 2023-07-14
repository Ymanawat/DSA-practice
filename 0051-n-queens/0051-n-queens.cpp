class Solution {
public:
    bool isSafe(int n, int row, int col, vector<int>& occupiedColumns, vector<int>& occupiedDiagonals, vector<int>& occupiedAntiDiagonals) {
        if (occupiedColumns[col] || occupiedDiagonals[row - col + n - 1] || occupiedAntiDiagonals[row + col])
            return false;
        
        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& result, vector<int>& occupiedColumns, vector<int>& occupiedDiagonals, vector<int>& occupiedAntiDiagonals) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(n, row, col, occupiedColumns, occupiedDiagonals, occupiedAntiDiagonals)) {
                board[row][col] = 'Q';
                occupiedColumns[col] = 1;
                occupiedDiagonals[row - col + n - 1] = 1;
                occupiedAntiDiagonals[row + col] = 1;

                solve(row + 1, n, board, result, occupiedColumns, occupiedDiagonals, occupiedAntiDiagonals);

                board[row][col] = '.';
                occupiedColumns[col] = 0;
                occupiedDiagonals[row - col + n - 1] = 0;
                occupiedAntiDiagonals[row + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        vector<int> occupiedColumns(n, 0);
        vector<int> occupiedDiagonals(2 * n, 0);
        vector<int> occupiedAntiDiagonals(2 * n, 0);

        solve(0, n, board, result, occupiedColumns, occupiedDiagonals, occupiedAntiDiagonals);

        return result;
    }
};

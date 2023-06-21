class Solution {
private:
    bool existHelper(vector<vector<char>>& board, string& word, int row, int col, int index) {
        if (index == word.length()) {
            return true;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[index]) {
            return false;
        }
        
        char original = board[row][col];
        board[row][col] = '#';
        
        if (existHelper(board, word, row + 1, col, index + 1) ||
            existHelper(board, word, row - 1, col, index + 1) ||
            existHelper(board, word, row, col + 1, index + 1) ||
            existHelper(board, word, row, col - 1, index + 1)) {
            return true;
        }
        
        board[row][col] = original;
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && existHelper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

class Solution {
public:
    bool dfs (vector<vector<char>>& board, string &word, int i, int j, int s, int n, int m, int *rowdir, int *coldir){
        
        if(s==word.size()) return true;
        if(i<0 || j<0 || i>=n ||j >=m ) return false;
        if(board[i][j]!=word[s]) return false;
        board[i][j] = '$';
        for(int k = 0; k<4; k++){
            if(dfs(board, word, i+rowdir[k], j+coldir[k], s+1, n, m, rowdir, coldir))return true;
        }
        board[i][j] = word[s];
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        int rowdir[] = {0, -1, 0, +1};
        int coldir[] = {+1, 0, -1, 0};

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (dfs(board, word, i, j, 0, n, m, rowdir, coldir)) return true;
        
        return false;
    }
};
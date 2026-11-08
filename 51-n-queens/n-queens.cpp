class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        int r = row, c = col;

        while(r >= 0 && c >= 0) {
            if(board[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }

        // Check upper-right diagonal
        r = row;
        c = col;

        while(r >= 0 && c < n) {
            if(board[r][c] == 'Q') {
                return false;
            }
            r--;
            c++;
        }
        return true;
    }

    void NQueens(vector<string>& board, int row, int n,vector<vector<string>>& ans) {

        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                NQueens(board, row + 1, n, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        NQueens(board, 0, n, ans);
        return ans;
    }
};
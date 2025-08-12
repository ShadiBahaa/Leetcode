class Solution {
public:
    int nn;
    vector<vector<string>> ans;

    bool ok(const vector<string>& board, int row, int col) {
        for (int i = 0; i < nn; ++i) {
            if (board[row][i] == 'Q') return false;
        }
        for (int i = 0; i < nn; ++i) {
            if (board[i][col] == 'Q') return false;
        }
        int i, j;
        i = row; j = col;
        while (i >= 0 && j >= 0) { if (board[i][j] == 'Q') return false; i--; j--; }
        i = row; j = col;
        while (i >= 0 && j < nn)  { if (board[i][j] == 'Q') return false; i--; j++; }
        i = row; j = col;
        while (i < nn && j >= 0)  { if (board[i][j] == 'Q') return false; i++; j--; }
        i = row; j = col;
        while (i < nn && j < nn)  { if (board[i][j] == 'Q') return false; i++; j++; }

        return true;
    }

    void solve(int row, vector<string>& board) {
        if (row == nn) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < nn; ++col) {
            if (ok(board, row, col)) {
                board[row][col] = 'Q';
                solve(row + 1, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        nn = n;
        vector<string> board(n, string(n, '.'));
        solve(0, board);
        return ans;
    }
};

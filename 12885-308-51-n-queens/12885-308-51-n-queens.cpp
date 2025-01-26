class Solution {
public:
    vector<vector<string>> ans;
    int nn;
    bool valid(int row, int col, vector<string> cur){
        for (int i = 0; i<nn; ++i){
            if (cur[row][i]=='Q')return false;
            if (cur[i][col]=='Q')return false;
        }
        int i = row;
        int j = col;
        while (true){
            if (i>=nn || j>=nn)break;
            if (cur[i][j]=='Q')return false;
            i++;
            j++;
        }
        i = row;
        j = col;
        while (true){
            if (i < 0 || j< 0)break;
            if (cur[i][j]=='Q')return false;
            i--;
            j--;
        }
        i = row;
        j = col;
        while (true){
            if (i < 0 || j>= nn)break;
            if (cur[i][j]=='Q')return false;
            i--;
            j++;
        }
        i = row;
        j = col;
        while (true){
            if (i >=nn || j<0)break;
            if (cur[i][j]=='Q')return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(int row,vector<string> cur){
        if (row == nn){
            ans.push_back(cur);
            return;
        }
        for (int col = 0; col < nn; ++col){
            if(valid(row,col,cur)){
                cur[row][col] = 'Q';
                backtrack(row+1,cur);
                cur[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        nn = n;
        vector<string> cur;
        for (int i = 0; i<n; ++i){
            string emp;
            for (int j = 0; j<n; ++j){
                emp += '.';
            }
            cur.push_back(emp);
        }
        backtrack(0,cur);
        return ans;
    }
};
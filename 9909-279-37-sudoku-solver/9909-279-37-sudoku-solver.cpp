class Solution {
public:
    bool valid(int row, int col, char c,     vector<vector<char>>& b
){
        for(int i = 0; i<9; ++i){
            if(b[row][i]==c)return false;
            if(b[i][col]==c)return false;
        }
        pair<int,int> startbox = {3*(row/3),3* (col/3)};
        pair<int,int> endbox = {startbox.first+2, startbox.second+2};
        for (int i = startbox.first; i<=endbox.first; ++i){
            for (int j = startbox.second; j<= endbox.second; ++j){
                if(b[i][j]==c)return false;
            }
        }
        //cout<<"lol"<<endl;
        return true;
    }
    bool backtrack(int row, int col,     vector<vector<char>>& b
){
        //cout<<row<<" "<<col<<endl;
        if (row == 9)return true;
        if(b[row][col]!='.') {
                int new_col = col+1;
                int new_row = row;
                if(new_col == 9){
                    new_col = 0;
                    new_row = row+1;
                }
                if (backtrack(new_row,new_col,b))return true;
            }
        for (char i = '1'; i<= '9'; ++i){
            if(b[row][col]=='.' && valid(row,col,i,b)){
                b[row][col] = i;
                int new_col = col+1;
                int new_row = row;
                if(new_col == 9){
                    new_col = 0;
                    new_row = row+1;
                }
                if (backtrack(new_row,new_col,b))return true;
                b[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(0,0,board);
    }
};
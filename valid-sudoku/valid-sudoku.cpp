class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (vector<char> v:board){
            set<char> s;
            for (char x:v){
                if (x=='.')continue;
                if (s.count(x))return false;
                s.insert(x);
            }
        }
        for (int i = 0; i<9; ++i){
            set<char> s;
            for (vector<char> v:board){
                if (v[i]=='.')continue;
                if (s.count(v[i]))return false;
                s.insert(v[i]);
            }
        }
        for (int begin = 0; begin<9; begin+=3){
            for (int end = 0; end<9; end+=3){
                set<char> s;
                for (int i = begin; i<begin+3; ++i){
                    for (int j = end; j<end+3; ++j){
                        if (board[i][j]=='.')continue;
                        else if (s.count(board[i][j]))return false;
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
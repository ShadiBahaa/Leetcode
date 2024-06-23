class Solution {
public:
    vector<vector<char>> mat;
    map<pair<int,int>,int> mp;
    int mm,nn;
    int dp(int i, int j){
        if (i<0 || j<0 || mat[i][j]=='0'){
            return 0;
        }
        if (mp.count({i,j}))return mp[{i,j}];
        int up = dp(i-1,j);
        int left = dp(i,j-1);
        int diag = dp(i-1,j-1);
        return mp[{i,j}] = 1 + min(up,min(left,diag));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        mm = matrix.size();
        nn = matrix[0].size();
        mat = matrix;
        int ans = 0;
        for (int i = 0; i<mm; ++i){
            for (int j = 0; j<nn; ++j)
                ans = max(ans,dp(i,j));
        }
        return ans*ans;
    }
};
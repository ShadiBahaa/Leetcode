class Solution {
public:
    int n;
    vector<vector<int>> mat;
    map<pair<int,int>,int> mp;
    int dp(int row, int col){
        if (row >=n)return 0;
        if (col>=n || col<0 || row<0)return 1e9;
        if (mp.count({row,col}))return mp[{row,col}];
        int call1 = mat[row][col],call2 = mat[row][col],call3 = mat[row][col];
        call1 += dp(row+1,col);
        call2 += dp(row+1,col-1);
        call3 += dp(row+1,col+1);
        return mp[{row,col}] = min(call1,min(call2,call3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        mat = matrix;
        int ans = 1e9;
        for (int i = 0; i<n; ++i){
            ans = min(ans,dp(0,i));
        }
        return ans;
    }
};
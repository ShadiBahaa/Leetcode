class Solution {
public:
    int mod = 1000000007;
    map<vector<int>,int> mp;
    int mm,nn;
    int dp(int row, int col, int rem){
        if (row < 0 || row >=mm || col < 0 || col >= nn)return 1;
        if (rem <= 0)return 0;
        if (mp.count({row,col,rem}))return mp[{row,col,rem}];
        int call1  = dp(row-1,col,rem-1)%mod;
        int call2  = dp(row+1,col,rem-1)%mod;
        int call3  = dp(row,col+1,rem-1)%mod;
        int call4  = dp(row,col-1,rem-1)%mod;
        return  mp[{row,col,rem}] = (((((call1 + call2)%mod)+call3)%mod)+call4)%mod; 
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        mm = m;
        nn = n;
        return dp(startRow,startColumn,maxMove);
    }
};
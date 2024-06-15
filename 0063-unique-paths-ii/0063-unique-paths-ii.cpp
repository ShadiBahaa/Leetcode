class Solution {
public:
    int m,n;
    vector<vector<int>> v;
    map<pair<int,int>,int> mp;
    int dp(int i , int j){
        if (i==(m-1) && j==(n-1))return 1;
        if (i>=m || j>=n || v[i][j]==1)return 0;
        if (mp.count({i,j}))return mp[{i,j}];
        int down = dp(i+1,j);
        int right = dp(i,j+1);
        return mp[{i,j}] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        v = obstacleGrid;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if (v[m-1][n-1]==1)return 0;
        return dp(0,0);
    }
};
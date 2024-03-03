class Solution {
public:
    map<pair<int,int>,int> dp;
    int sz;
    vector<vector<int>> tmp;
    bool less_eq(int i, int j){
        return tmp[i][1]<=tmp[j][1] && tmp[i][2]<=tmp[j][2];
    }
    int lis(int i, int prev){
        if (i==sz)return 0;
        if (dp.count({i,prev}))return dp[{i,prev}];
        int ans = lis(i+1,prev);
        if (prev == -1 || less_eq(prev,i)){
            ans = max(ans,tmp[i][2]+lis(i+1,i));
        }
        return dp[{i,prev}] = ans;
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &cub : cuboids){
            sort(cub.begin(),cub.end());
        }
        sort(cuboids.begin(),cuboids.end());
        sz = cuboids.size();
        tmp = cuboids;
        return lis(0,-1);
    }
};
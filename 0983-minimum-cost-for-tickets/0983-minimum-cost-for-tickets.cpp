class Solution {
public:
    
    int dfs(int i, vector<int>& days,int &n, vector<int>& costs,map<int,int> & dp){
        if (i == n)return 0;
        if (dp.count(i))return dp[i];
        vector<int> counts = {1,7,30};
        dp[i] = INT_MAX;
        for (int j = 0 ; j < 3; ++j){
            int k = i;
            while((k < n) && (days[k] < (days[i]+counts[j]))){
                k++;
            }
            dp[i] = min(dp[i], costs[j] + dfs(k,days,n,costs,dp));
        }
        return dp[i];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<int,int> dp;
        int n = days.size();
        return dfs(0,days,n,costs, dp);
    }
};
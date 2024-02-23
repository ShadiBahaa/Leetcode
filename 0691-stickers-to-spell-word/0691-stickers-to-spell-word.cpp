class Solution {
public:
    int dfs(string target, vector<int>& tmp,vector<vector<int>>& counts, map<string,int>& dp, bool flag){
        if (dp.count(target))return dp[target];
        string remain;
        int ans;
        if (flag) ans = 0;
        else ans = 1;
        for (char c : target){
            if (tmp[c - 'a'] > 0){
                tmp[c - 'a']--;
            }else {
                remain+=c;
            }
        }
        if (remain.size()){
            int additional = INT_MAX;
            char cur = remain[0];
            for (int i = 0; i<counts.size(); ++i){
            if (counts[i][cur-'a']>0){
                tmp = counts[i];
                additional = min(additional, dfs(remain,tmp,counts,dp,false));
            }
            
        }
            dp[remain] = additional;
            if (additional == INT_MAX){
                ans = INT_MAX;
            }else {
                ans += additional;
            }
        }
        return ans;
        
        
    }
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> counts(stickers.size(),vector<int>(26));
        map<string,int> dp;
        for (int i = 0; i<stickers.size() ; ++i){
            for (int j = 0; j<stickers[i].size(); ++j){
                counts[i][stickers[i][j]-'a']++;
            }
        }
        vector<int> tmp(26);
        int res = dfs(target,tmp,counts,dp,true);
        return (res==INT_MAX)?-1:res;
    }
};
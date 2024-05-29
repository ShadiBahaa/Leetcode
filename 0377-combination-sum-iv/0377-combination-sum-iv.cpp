class Solution {
public:
    int tar;
    vector<int> numm;
    map<pair<int,int>,int> mp;
    int dp(int i , int sum){
        if (i >= numm.size())return 0;
        if (sum > tar)return 0;
        if (sum == tar)return 1;
        if (mp.count({i,sum}))return mp[{i,sum}];
        int ans = 0;
        for (int j = 0; j < numm.size(); ++j){
            ans += dp(j,sum + numm[j]);
        }
        return mp[{i,sum}] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        numm = nums;
        tar = target;
        return dp(0,0);
    }
};
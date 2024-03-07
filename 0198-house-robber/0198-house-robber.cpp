class Solution {
public:
    vector<int> tmp;
    map<int,int> mp;
    int dp(int idx){
        if (idx >= tmp.size())return 0;
        if (mp.count(idx))return mp[idx];
        int call1 = dp(idx+1);
        int call2 = tmp[idx] + dp(idx+2);
        return mp[idx] = max(call1,call2);
    }
    int rob(vector<int>& nums) {
        tmp = nums;
        return dp(0);
    }
};
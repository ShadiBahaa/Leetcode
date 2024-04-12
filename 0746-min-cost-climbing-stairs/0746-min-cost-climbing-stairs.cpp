class Solution {
public:
    vector<int> cos;
    map<int,int> mp;
    int dp(int i){
        if (i>=(int)cos.size())return 0;
        if (mp.count(i))return mp[i];
        int call1 = ((i!=-1)?cos[i]:0) + dp(i+1);
        int call2 = ((i!=-1)?cos[i]:0) + dp(i+2);
        return mp[i] = min(call1,call2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cos = cost;
        return dp(-1);
    }
};
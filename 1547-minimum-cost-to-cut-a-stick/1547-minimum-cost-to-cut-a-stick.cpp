class Solution {
public:
    vector<int> cut;
    map<pair<int,int>,int> mp;
    int dp(int start, int end){
        if ((start + 1)==end)return 0;
        if (mp.count({start,end}))return mp[{start,end}];
        int ans = 1e9;
        for (int split = start + 1; split < end; ++ split){
            int left = dp(start,split);
            int right = dp(split,end);
            int cost = cut[end] - cut[start];
            ans = min(ans,left + right + cost);
        }
        return mp[{start,end}] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cut = cuts;
        cut.push_back(0);
        cut.push_back(n);
        sort(cut.begin(),cut.end());
        return dp(0,cut.size()-1);
    }
};
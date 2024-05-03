class Solution {
public:
    map<pair<int,int>,int> mp;
    string tmp;
    int dp(int start,int end){
        if (start >= end)return 0;
        if (mp.count({start,end}))return mp[{start,end}];
        int res = INT_MAX;
        if (tmp[start]==tmp[end])return mp[{start,end}] = dp(start+1,end-1);
        res = min(res, 1 + dp(start+1,end));
        res = min(res, 1 + dp(start,end-1));
        return mp[{start,end}] = res;
    }
    int minInsertions(string s) {
        tmp = s;
        return dp(0,s.size()-1);
    }
};
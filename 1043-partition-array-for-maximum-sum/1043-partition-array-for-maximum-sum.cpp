class Solution {
public:
    vector<int> v;
    int kk;
    map<int,int> mp;
    int dp(int i){
        if (i >= v.size())return 0;
        if (mp.count(i))return mp[i];
        int ans = 0;
        int cnt = 0;
        int val = -1;
        for (int j = i; j<v.size(); ++j){
            cnt++;
            val = max(val,v[j]);
            if (cnt <= kk){
            }else {
                cnt = 1;
                val = v[j];
            }
            ans = max(ans,val*cnt + dp(j+1));
        }
        return mp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        kk = k;
        v = arr;
        return dp(0);
    }
};
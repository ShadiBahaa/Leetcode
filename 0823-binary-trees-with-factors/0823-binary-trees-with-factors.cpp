class Solution {
public:
    set<int> val;
    int mod = 1000000007;
    map<int,int> mp;
    int dp(int x){
        if (mp.count(x))return mp[x];
        int ans = 1;
        for (int v : val){
            if (x%v==0 && val.count(x/v)){
                ans += ((long long )dp(v)*(long long )dp(x/v))%mod;
                ans %= mod;
            }
        }
        return mp[x] = ans;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        set<int> num(arr.begin(),arr.end());
        val = num;
        int cnt = 0;
        for (int x : num){
            cnt += dp(x);
            cnt %= mod;
        }
        return cnt;
    }
};
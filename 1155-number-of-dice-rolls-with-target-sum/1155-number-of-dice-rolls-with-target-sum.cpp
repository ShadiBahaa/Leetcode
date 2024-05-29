class Solution {
public:
    map<vector<int>,int> mp;
    int mod = 1000000000 + 7;
    int numRollsToTarget(int n, int k, int target) {
        if (n == 0 && target == 0)return 1;
        if (target < 0)return 0;
        if (n == 0)return 0;
        if (mp.count({n,k,target})) return mp[{n,k,target}];
        int ans = 0;
        for (int i = 1; i<=k; ++i){
            ans = ((ans % mod) + (numRollsToTarget(n-1,k,target - i) % mod))%mod;
        }
        return mp[{n,k,target}] = ans;
    }
};
class Solution {
public:
    int mod = 1000000007;
    int mp[20005][7];
    int dp(int n, int chosen){
        if (n == 0)return 1;
        if (mp[n][chosen+1]!=-1)return mp[n][chosen+1];
        int ans = 0;
        if (chosen == -1){
            ans += dp(n-1,1)%mod;
            ans %= mod;
            ans += dp(n-1,2)%mod;
            ans %= mod;
            ans += dp(n-1,3)%mod;
            ans %= mod;
            ans += dp(n-1,4)%mod;
            ans %= mod;
            ans += dp(n-1,5)%mod;
            ans %= mod;
        }else {
            if (chosen == 1){
                ans += dp(n-1,2)%mod;
                ans %= mod;
            }else if (chosen == 2){
                ans += dp(n-1,1)%mod;
                ans %= mod;
                ans += dp(n-1,3)%mod;
                ans %= mod;
            }else if (chosen == 3){
                ans += dp(n-1,1)%mod;
                ans %= mod;
                ans += dp(n-1,2)%mod;
                ans %= mod;
                ans += dp(n-1,4)%mod;
                ans %= mod;
                ans += dp(n-1,5)%mod;
                ans %= mod;
            }else if (chosen == 4){
                ans += dp(n-1,3)%mod;
                ans %= mod;
                ans += dp(n-1,5)%mod;
                ans %= mod;
            }else if (chosen == 5){
                ans += dp(n-1,1)%mod;
                ans %= mod;
            }
        }
        return mp[n][chosen+1] = ans;
    }
    int countVowelPermutation(int n) {
        memset(mp,-1,sizeof(mp));
        return dp(n,-1);
    }
};
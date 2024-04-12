class Solution {
public:
    int mp[10000+5];
    int dp(int n){
        if (n==0)return 0;
        if (mp[n]!=-1)return mp[n];
        int res = 1e9;
        for (int i = 1; i<=n; ++i){
            if ((n - i*i) >= 0){
                res = min(res,1 + dp(n-i*i));
            }else {
                break;
            }
        }
        return mp[n] = res;
    }
    int numSquares(int n) {
        memset(mp,-1,sizeof(mp));
        return dp(n);
    }
};
class Solution {
public:
    map<int,int> mp;
    int dp(int n, int k){
        if (n==1)return 1;
        if (mp.count(n))return mp[n];
        int res = n;
        for (int i = 1; i<n; ++i){
            res = max(res,i*dp(n-i,k-1));
        }
        return mp[n] = res;
    }
    int integerBreak(int n) {
        if (n==2 || n==3)return n-1;
        return dp(n,n-2);
    }
};
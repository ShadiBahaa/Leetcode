class Solution {
public:
    int mod = 1000000007;
    int numberOfWays(string corridor) {
        vector<int> v;
        int n = corridor.size();
        for (int i = 0; i<n; ++i){
            if (corridor[i]=='S')
            v.push_back(i);
        }
        n = v.size();
        if (n<2 || n%2)return 0;
        int i = 1;
        long ans = 1;
        while (i < (n-1)){
            ans = (ans%mod * ((v[i+1]-v[i])%mod))%mod;
            i+=2;
        }
        return (int)ans;
    }
};
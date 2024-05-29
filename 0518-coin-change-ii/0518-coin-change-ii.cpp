class Solution {
public:
    int am;
    vector<int> co;
    map<pair<int,int>,int> mp;
    int dp(int i, int sum){
        if (i>=co.size())return 0;
        if (sum > am)return 0;
        if (sum == am)return 1;
        if (mp.count({i,sum}))return mp[{i,sum}];
        
        int ans = dp(i+1,sum);
        if ((sum+co[i]) <= am){
            ans += dp(i,sum+co[i]);
        }
        return mp[{i,sum}] = ans;
    }
    int change(int amount, vector<int>& coins) {
        co = coins;
        am = amount;
        return dp(0,0);
    }
};
class Solution {
public:
    vector<int> tmp;
    enum {
      NOTHING,
      SELL,
      BUY  
    }e;
    map<vector<int>,int> mp;
    int dp(int idx, int pick, int last){
        if (idx >= tmp.size())return 0;
        if (mp.count({idx,pick,last}))return mp[{idx,pick,last}];
        int call1 = dp(idx+1,pick,NOTHING);
        int call2 = 0, call3 = 0;
        if (pick){
            call2 = tmp[idx] + dp(idx+1,0,SELL);
        }else if (last != SELL){
            call3 = -tmp[idx] + dp(idx+1,1,BUY);
        }
        return mp[{idx,pick,last}] = max(call1,max(call2,call3));
    }
    int maxProfit(vector<int>& prices) {
        tmp = prices;
        return dp(0,0,NOTHING);
    }
};
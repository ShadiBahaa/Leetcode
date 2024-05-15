class Solution {
public:
    map<int,int> mp;
    string ss;
    int dp(int i){
        if (i >= ss.size())return 1;
        if (mp.count(i))return mp[i];
        int ans = 0;
        if (ss[i]!='0'){
            ans += dp(i+1);
        }
        if ((i+1)<ss.size() && (ss[i]=='1' || (ss[i]=='2' && ss[i+1]>='0' && ss[i+1]<='6'))){
            ans += dp(i+2);
        }
        return mp[i] = ans;
    }
    int numDecodings(string s) {
        ss = s;
        return dp(0);
    }
};
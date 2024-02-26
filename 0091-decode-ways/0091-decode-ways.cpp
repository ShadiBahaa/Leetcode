class Solution {
public:
    int decode(int idx, string& s, map<int,int> & mp){
        if (mp.count(idx))return mp[idx];
        if (s[idx]=='0')return 0;
        int res = decode(idx+1,s,mp);
        if ((idx+1) < s.size() && (s[idx]=='1' || (s[idx]=='2' && s[idx+1]>='0' && s[idx+1]<='6'))){
            res += decode(idx+2,s,mp);
        }
        return mp[idx] = res;
    }
    int numDecodings(string s) {
        map<int,int> mp;
        mp[s.size()] = 1;
        return decode(0,s,mp);
    }
};
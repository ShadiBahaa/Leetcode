class Solution {
public:
    int lcs(int idx1, int idx2, string & text1, string & text2, map<pair<int,int>,int> & mp){
        if (idx1 == text1.size() || idx2==text2.size())return 0;
        if (mp.count({idx1,idx2}))return mp[{idx1,idx2}];
        int ans = 0;
        if (text1[idx1]==text2[idx2]){
            ans = 1 + lcs(idx1+1,idx2+1,text1,text2,mp);
        }else {
            ans = max(lcs(idx1+1,idx2,text1,text2,mp),lcs(idx1,idx2+1,text1,text2,mp));
        }
        return mp[{idx1,idx2}] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        map<pair<int,int>,int> mp;
        return lcs(0,0,text1,text2,mp);
    }
};
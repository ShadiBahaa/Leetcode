class Solution {
public:
    string str;
    int mp[1005][1005];
    bool is_pal(int start, int end){
        if (start >= end)return true;
        if (mp[start][end]!=-1)return mp[start][end];
        if (str[start]==str[end]){
            return mp[start][end] = is_pal(start+1,end-1);
        }
        return mp[start][end] =  false;
    }
    string longestPalindrome(string s) {
        memset(mp,-1,sizeof(mp));
        str = s;
        int idx = -1;
        int length = 0;
        int sz = s.size();
        for (int i = 0; i<sz; ++i){
            for (int j = i; j<sz; ++j){
                int len = j-i+1;
                if (is_pal(i,j) && len>length){
                    idx = i, length = len;
                } 
            }
        }
        return s.substr(idx,length);
    }
};
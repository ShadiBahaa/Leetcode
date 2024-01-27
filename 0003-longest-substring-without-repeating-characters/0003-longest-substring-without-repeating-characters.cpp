class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> dq;
        map<char,int> mp;
        int ans = 0;
        for (char c : s){
            if (mp[c]){
                ans = max((int)dq.size(),ans);
                while (dq.size()){
                    if (dq[0] == c){
                        dq.pop_front();
                        break;
                    }else {
                        mp[dq[0]] = 0;
                        dq.pop_front();
                    }
                }
            }else {
                mp[c] = 1;
            }
            dq.push_back(c);
        }
        if (dq.size()) ans = max(ans,(int)dq.size());
        return ans;
    }
};
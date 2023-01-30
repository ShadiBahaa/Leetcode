class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        for (int i = 0; i<s.size(); ++i){
            if (!mp[s[i]]){
                for (auto it = mp.begin(); it != mp.end(); it++){
                    if (it->second==t[i])return false;
                }
                mp[s[i]] = t[i];
            }
            else {
                if (mp[s[i]]!=t[i])return false;
            }
        }
        return true;
    }
};
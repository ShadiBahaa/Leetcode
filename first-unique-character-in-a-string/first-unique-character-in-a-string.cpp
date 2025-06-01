class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> um;
        for (int i = 0 ; i < s.size(); ++i){
            um[s[i]]++;
        }
        for(int i = 0; i<s.size(); ++i){
            if(um[s[i]]==1)return i;
        }
        return -1;
    }
};
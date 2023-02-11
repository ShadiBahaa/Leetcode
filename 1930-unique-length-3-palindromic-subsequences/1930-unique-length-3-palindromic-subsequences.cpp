class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<char> left;
        map<char,int> right;
        for (char x:s)right[x]++;
        set<pair<char,char>> res;
        for (char x:s){
            right[x]--;
            for (char c = 'a'; c<='z'; ++c){
                if (left.count(c) && right[c])res.insert({x,c});
            }
            left.insert(x);
        }
        return res.size();
    }
};
class Solution {
public:
    map<char,string> mp;
    vector<string> ans;
    string tmp;
    void combine(int ind, string cur){
        if(ind==tmp.size()){
            ans.push_back(cur);
            return;
        }
        for (char c : mp[tmp[ind]]){
            combine(ind + 1, cur +c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        tmp = digits;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        combine(0,"");
        return ans;
    }
};
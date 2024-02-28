class Solution {
public:
    void backtrack(int i, int dots, string cur, string& s, vector<string>& res){
        if (dots==4 && i==s.size()){
            cur.pop_back();
            res.push_back(cur);
            return;
        }
        if (dots>4){
            return;
        }
        string tmp;
        for (int j = i; j<min(i+3,(int)s.size()); ++j){
            tmp+=s[j];
            if (stoi(tmp)<256 && (i==j || tmp[0]!='0')){
                backtrack(j+1,dots+1,cur + tmp + '.', s,res);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size()>12)return res;
        backtrack(0,0,"",s,res);
        return res;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string comm = "";
        for (int i = 0; i<(strs[0]).size(); ++i){
            char c = strs[0][i];
            bool same = true;
            for (int j = 1; j<strs.size(); ++j){
                if (strs[j][i]!=c){
                    same = false;
                    break;
                }
            }
            if (same){
                comm+=c;
            }else {
                break;
            }
        }
        return comm;
    }
};
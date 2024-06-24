class Solution {
public:
    string ss;
    vector<string> tmp;
    vector<vector<string>> ans;
    bool is_pal(string s, int left, int right){
        while (left < right){
            if (s[left]!=s[right])return false;
            left ++;
            right --;
        }
        return true;
    }
    void back(int i){
        if (i>=ss.size()){
            ans.push_back(tmp);
            return;
        }
        for (int j = i; j<ss.size(); ++j){
            string sub = ss.substr(i,j-i+1);
            if (is_pal(ss,i,j)){
                tmp.push_back(sub);
            back(j+1);
            tmp.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        ss = s;
        back(0);
        return ans;
    }
};
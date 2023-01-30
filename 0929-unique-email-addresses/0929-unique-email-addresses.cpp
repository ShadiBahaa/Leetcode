class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for (int i = 0 ; i<emails.size(); ++i){
            string tmp = emails[i];
            for (int j = 0; j<tmp.size() && tmp[j]!='@'; ++j){
                if (tmp[j]=='.'){
                    tmp = tmp.substr(0,j)+tmp.substr(j+1);
                    j--;
                }
                else if (tmp[j]=='+') {
                    tmp = tmp.substr(0,j)+tmp.substr(tmp.find('@'));
                    break;
                }
            }
            s.insert(tmp);
        }
        return s.size();
    }
};
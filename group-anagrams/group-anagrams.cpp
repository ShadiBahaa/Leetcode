class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for (string element:strs){
            string tmp = element;
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(element);
        }
        vector<vector<string>> v(mp.size());
        int cnt = 0;
        for (pair<string,vector<string>> ele:mp){
            for (string s:ele.second){
                v[cnt].push_back(s);
            }
            cnt++;
        }
        return v;
    }
};
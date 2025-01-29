class Solution {
public:
    set<vector<int>> ans;
    vector<int> n;
    void backtrack(int idx, vector<int> cur, vector<bool> vis){
        if (idx == n.size()){
            ans.insert(cur);
            return;
        }
        for(int i = 0; i < n.size(); ++i){
            if(!vis[i]){
               vis[i] = true;
               cur.push_back(n[i]);
               backtrack(idx+1,cur,vis);
               vis[i] = false;
               cur.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums;
        vector<bool> vis(n.size());
        backtrack(0,{},vis);
        vector<vector<int>> res;
        for (vector<int> v : ans)res.push_back(v);
        return res;
    }
};
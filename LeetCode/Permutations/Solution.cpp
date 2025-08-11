class Solution {
public: 
    vector<vector<int>> ans;
    void call(const vector<int>& nums, vector<int> cur, vector<bool> vis){
        if(cur.size() == nums.size()){
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i<nums.size(); ++i){
            if (!vis[i]){
                vis[i] = true;
                cur.push_back(nums[i]);
                call(nums,cur,vis);
                cur.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size());
        call(nums,{},vis);
        return ans;
    }
};
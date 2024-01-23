class Solution {
public:
    void dfs(int i, vector<int>& tmp ,vector<vector<int>>& ans, vector<int>& nums){
        if (i >= nums.size()){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[i]);
        dfs(i+1,tmp,ans,nums);
        tmp.pop_back();
        dfs(i+1,tmp,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(0,tmp,ans,nums);
        return ans;
    }
};
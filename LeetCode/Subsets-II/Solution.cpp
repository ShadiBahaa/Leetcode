class Solution {
public:
    set<vector<int>> ans;
    void call(vector<int> & nums, vector<int> cur, int ind){
        if(ind == nums.size()){
            sort(cur.begin(),cur.end());
            ans.insert(cur);
            return;
        }
        call(nums,cur,ind+1);
        cur.push_back(nums[ind]);
        call(nums,cur,ind+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        call(nums,{},0);
        vector<vector<int>> v(ans.begin(),ans.end());
        return v;
    }
};
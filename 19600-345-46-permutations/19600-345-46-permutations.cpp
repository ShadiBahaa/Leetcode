class Solution {
public:
    vector<vector<int>> ans;
    vector<int> n;
    void backtrack(int idx,vector<int> cur){
        if(idx==n.size()){
            ans.push_back(cur);
            return;
        }
        for (int ele : n){
            if(find(cur.begin(),cur.end(),ele)==cur.end()){
                cur.push_back(ele);
                backtrack(idx+1,cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums;
        backtrack(0,{});
        return ans;
    }
};
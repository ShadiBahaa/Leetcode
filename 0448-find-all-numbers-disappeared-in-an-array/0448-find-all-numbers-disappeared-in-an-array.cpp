class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        set<int> s(nums.begin(),nums.end());
        for (int i = 1; i<=(int)nums.size(); ++i){
            if (!s.count(i))ans.push_back(i);
        }
        return ans;
    }
};
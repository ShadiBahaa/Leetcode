class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<pair<int,int>> s;
        for (int i = 0; i<nums.size(); ++i){
            s.insert({nums[i],i});
        }
        for (auto element:s){
            auto it = s.lower_bound({target-element.first,element.second+1});
            if (it!=s.end() && it->first==target-element.first){
                return {element.second,it->second};
            }
        }
        return {};
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<nums.size(); ++i){
            mp[nums[i]].push_back(i);
        }
        for(auto it:mp){
            vector<int> sec = it.second;
            for(int i = 0; i<sec.size(); ++i){
                for (int j = i+1; j<sec.size(); ++j){
                    if(abs(sec[i]-sec[j])<=k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};